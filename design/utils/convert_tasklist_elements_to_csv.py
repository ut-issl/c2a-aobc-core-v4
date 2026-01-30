#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
src/src_user/settings/modes/task_lists/elements 配下の各 .c ファイルと
1 対 1 で対応する CSV を design/bct/tasklist_elements/{basename}.csv に出力する。

CSV 形式は nbc_tl_elems.csv 等と同じ:
subsystem,name,bcid,type,option,ti,cmd,args,description,note

- function 名 BCL_load_xxx → 先頭行に name=BC_XXX を出力
- BCL_tool_register_app(ti, CMD) を app 行として出力
- ti が数値リテラルでない場合は空欄
- subsystem / bcid / option / args / description / note はソースに情報が無いので基本空欄
  note には元 C ファイルの相対パスを入れる
"""
from __future__ import annotations

import csv
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
TASKLIST_ROOT = ROOT / "src" / "src_user" / "settings" / "modes" / "task_lists"
ELEMENT_DIR = TASKLIST_ROOT / "elements"
OUT_DIR_ELEM = ROOT / "design" / "bct" / "task_lists" / "elements"
OUT_DIR_TASK = ROOT / "design" / "bct" / "task_lists"
TRANSITION_DIR = ROOT / "src" / "src_user" / "settings" / "modes" / "transitions"
OUT_DIR_TRANS = ROOT / "design" / "bct" / "transitions"
NORMAL_BC_DIR = ROOT / "src" / "src_user" / "tlm_cmd" / "normal_block_command_definition"
OUT_DIR_NORMAL_BC = ROOT / "design" / "bct" / "normal_block_command_definition"

HEADER = ["subsystem", "name", "bcid", "type", "option", "ti", "cmd", "args", "description", "note"]

# void BCL_load_xxx(...) {
FUNC_RE = re.compile(r"void\s+(BCL_load_[A-Za-z0-9_]+)\s*\([^)]*\)\s*{", re.MULTILINE)
# BCL_tool_register_app( ti , CMD );
REG_APP_RE = re.compile(r"BCL_tool_register_app\s*\(\s*([^,]+?)\s*,\s*([^\)]+?)\s*\)")
# BCL_tool_register_combine/rotate/deploy
REG_COMBINE_RE = re.compile(r"BCL_tool_register_(combine|rotate)\s*\(\s*([^,]+?)\s*,\s*([^\)]+?)\s*\)")
REG_DEPLOY_RE = re.compile(r"BCL_tool_register_deploy\s*\(\s*([^,]+?)\s*,\s*([^,]+?)\s*,\s*([^\)]+?)\s*\)")
# BCL_tool_register_cmd
REG_CMD_RE = re.compile(r"BCL_tool_register_cmd\s*\(\s*([^,]+?)\s*,\s*([^\)]+?)\s*\)")
# BCL_tool_prepare_param_xxx
REG_PREPARE_PARAM_RE = re.compile(r"BCL_tool_prepare_param_([A-Za-z0-9_]+)\s*\(\s*([^\)]+?)\s*\)")
# 簡単な代入/加算文
ASSIGN_RE = re.compile(r"(?:\w+\s+)?(\w+)\s*=\s*(.+);")
PLUS_ASSIGN_RE = re.compile(r"(\w+)\s*\+=\s*(.+);")
INC_RE = re.compile(r"(\w+)\s*\+\+\s*;")

# 定数定義ファイルから値を引く（単純な数式対応）
CONST_PATH = ROOT / "src" / "src_user" / "settings" / "SatelliteParameters" / "Sample" / "fdir_parameters.c"
CONST_DEF_RE = re.compile(r"\bconst\s+\w+\s+(?P<name>[A-Za-z0-9_]+)\s*=\s*(?P<expr>[^;]+);")

def load_const_map():
    mapping = {}
    if not CONST_PATH.exists():
        return mapping
    text = CONST_PATH.read_text(encoding="utf-8")
    for m in CONST_DEF_RE.finditer(text):
        expr = m.group("expr").strip()
        try:
            val = safe_eval_expr(expr, {})
            mapping[m.group("name")] = val
        except Exception:
            continue
    return mapping

def safe_eval_expr(expr: str, vars_map: dict):
    """OBCT_sec2cycle(n) を 10*n とみなし、vars_map と定数を使って簡易評価する。"""
    def replace_obct(s: str) -> str:
        return re.sub(r"OBCT_sec2cycle\(([^)]+)\)", r"(10* (\1))", s)
    expr2 = replace_obct(expr)
    # 変数を数字に置換
    def repl_var(match):
        name = match.group(0)
        if name in vars_map:
            return str(vars_map[name])
        if name in CONST_MAP:
            return str(CONST_MAP[name])
        return name
    expr2 = re.sub(r"\b[A-Za-z_][A-Za-z0-9_]*\b", repl_var, expr2)
    return eval(expr2, {"__builtins__": None}, {})

CONST_MAP = load_const_map()

def to_bc_name(func_name: str) -> str:
    """
    BCL_load_xxx -> BC_XXX に変換するだけ（プレフィックス AC/AR を付けない）。
    """
    base = func_name.replace("BCL_load_", "")
    snake = re.sub(r"(?<!^)(?=[A-Z])", "_", base).replace("__", "_").upper()
    return f"BC_{snake}"


def _append_description(row: dict, comment: str) -> None:
    if not comment:
        return
    if row.get("description"):
        row["description"] += " / " + comment
    else:
        row["description"] = comment


def parse_file(path: Path):
    text = path.read_text(encoding="utf-8")
    pending_comment = ""  # 直前に見つけたコメント（次の行に適用）
    vars_map = {}
    last_row: dict | None = None  # 直近に出力した行（時間加算行のコメントを追記するため）
    for func_match in FUNC_RE.finditer(text):
        func_name = func_match.group(1)
        func_start = func_match.end()
        brace_level = 1
        i = func_start
        while i < len(text) and brace_level > 0:
            if text[i] == "{":
                brace_level += 1
            elif text[i] == "}":
                brace_level -= 1
            i += 1
        body = text[func_start:i - 1]

        bc_name = to_bc_name(func_name)
        header_row = {
            "subsystem": "AOCS",
            "name": bc_name or "",
            "bcid": "",
            "type": "",
            "option": "",
            "ti": "",
            "cmd": "",
            "args": "",
            "description": "",
            "note": "",
        }
        last_row = header_row
        yield header_row

        for line in body.splitlines():
            line_body, inline_cmt = (line.split("//", 1) + [""])[:2] if "//" in line else (line, "")
            inline_cmt = inline_cmt.strip()
            stripped = line_body.strip()

            if not stripped:
                if inline_cmt:
                    pending_comment = inline_cmt
                continue
            if stripped.startswith("/*"):
                continue
            if stripped.startswith("//"):
                pending_comment = inline_cmt or stripped[2:].strip()
                continue
            # 代入/加算を簡易評価して変数に保存（時間加算行のコメントは直前の行に追記する）
            m_assign = ASSIGN_RE.match(stripped)
            if m_assign:
                var, expr = m_assign.group(1), m_assign.group(2)
                try:
                    vars_map[var] = safe_eval_expr(expr, vars_map)
                except Exception:
                    vars_map[var] = expr  # 失敗したらそのまま保持
                if inline_cmt and last_row:
                    _append_description(last_row, inline_cmt)
                else:
                    pending_comment = inline_cmt or pending_comment
                continue
            m_inc = INC_RE.match(stripped)
            if m_inc:
                var = m_inc.group(1)
                cur = vars_map.get(var, 0)
                try:
                    vars_map[var] = cur + 1 if isinstance(cur, (int, float)) else cur
                except Exception:
                    pass
                if inline_cmt and last_row:
                    _append_description(last_row, inline_cmt)
                else:
                    pending_comment = inline_cmt or pending_comment
                continue
            # parameter prepare（1行として出力）
            m_param = REG_PREPARE_PARAM_RE.search(stripped)
            if m_param:
                kind, val_raw = m_param.group(1), m_param.group(2).strip()
                try:
                    val_num = safe_eval_expr(val_raw, vars_map)
                    val_str = str(val_num)
                except Exception:
                    val_str = val_raw
                description_parts = [c for c in (pending_comment, inline_cmt) if c]
                description = " / ".join(description_parts)
                row = {
                    "subsystem": "",
                    "name": "",
                    "bcid": "",
                    "type": "param",
                    "option": kind,
                    "ti": "",
                    "cmd": "",
                    "args": val_str,
                    "description": description,
                    "note": "",
                }
                last_row = row
                yield row
                pending_comment = ""
                continue
            m_plus = PLUS_ASSIGN_RE.match(stripped)
            if m_plus:
                var, expr = m_plus.group(1), m_plus.group(2)
                try:
                    add_val = safe_eval_expr(expr, vars_map)
                    cur = vars_map.get(var, 0)
                    if isinstance(cur, (int, float)) and isinstance(add_val, (int, float)):
                        vars_map[var] = cur + add_val
                    else:
                        vars_map[var] = expr
                except Exception:
                    pass
                if inline_cmt and last_row:
                    _append_description(last_row, inline_cmt)
                else:
                    pending_comment = inline_cmt or pending_comment
                continue
            m = REG_APP_RE.search(stripped)
            if not m:
                # combine / rotate
                m2 = REG_COMBINE_RE.search(stripped)
                if m2:
                    kind, ti_raw, cmd_raw = m2.group(1), m2.group(2).strip(), m2.group(3).strip()
                    ti_val = ti_raw if ti_raw.isdigit() else ""
                    description_parts = [c for c in (pending_comment, inline_cmt) if c]
                    description = " / ".join(description_parts)
                    row = {
                        "subsystem": "",
                        "name": "",
                        "bcid": "",
                        "type": kind,
                        "option": "",
                        "ti": ti_val,
                        "cmd": cmd_raw,
                        "args": "",
                        "description": description,
                        "note": "",
                    }
                    last_row = row
                    yield row
                    pending_comment = ""
                    continue
                # deploy
                m3 = REG_DEPLOY_RE.search(stripped)
                if m3:
                    ti_raw, cmd_raw, opt_raw = m3.group(1).strip(), m3.group(2).strip(), m3.group(3).strip()
                    try:
                        ti_val_num = safe_eval_expr(ti_raw, vars_map)
                        ti_val = str(int(ti_val_num))
                    except Exception:
                        ti_val = ti_raw if ti_raw.isdigit() else ""
                    description_parts = [c for c in (pending_comment, inline_cmt) if c]
                    description = " / ".join(description_parts)
                    row = {
                        "subsystem": "",
                        "name": "",
                        "bcid": "",
                        "type": "deploy",
                        "option": opt_raw,
                        "ti": ti_val,
                        "cmd": cmd_raw,
                        "args": "",
                        "description": description,
                        "note": "",
                    }
                    last_row = row
                    yield row
                    pending_comment = ""
                    continue
                # cmd
                m4 = REG_CMD_RE.search(stripped)
                if m4:
                    ti_raw, cmd_raw = m4.group(1).strip(), m4.group(2).strip()
                    try:
                        ti_val_num = safe_eval_expr(ti_raw, vars_map)
                        ti_val = str(int(ti_val_num))
                    except Exception:
                        ti_val = ti_raw if ti_raw.isdigit() else ""
                    description_parts = [c for c in (pending_comment, inline_cmt) if c]
                    description = " / ".join(description_parts)
                    row = {
                        "subsystem": "",
                        "name": "",
                        "bcid": "",
                        "type": "cmd",
                        "option": "",
                        "ti": ti_val,
                        "cmd": cmd_raw,
                        "args": "",
                        "description": description,
                        "note": "",
                    }
                    last_row = row
                    yield row
                    pending_comment = ""
                    continue
                continue
            # app
            ti_raw, cmd_raw = m.group(1).strip(), m.group(2).strip()
            try:
                ti_val_num = safe_eval_expr(ti_raw, vars_map)
                ti_val = str(int(ti_val_num))
            except Exception:
                ti_val = ti_raw if ti_raw.isdigit() else ""
            description_parts = [c for c in (pending_comment, inline_cmt) if c]
            description = " / ".join(description_parts)
            row = {
                "subsystem": "",
                "name": "",
                "bcid": "",
                "type": "app",
                "option": "",
                "ti": ti_val,
                "cmd": cmd_raw,
                "args": "",
                "description": description,
                "note": "",
            }
            last_row = row
            yield row
            pending_comment = ""


def write_csv_for_file(c_path: Path, out_dir: Path, prefix: str = "bc_"):
    rows = list(parse_file(c_path))
    out = out_dir / (prefix + c_path.stem + ".csv")
    out_dir.mkdir(parents=True, exist_ok=True)
    with out.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=HEADER)
        writer.writeheader()
        for row in rows:
            writer.writerow(row)
    return out


def main():
    generated = []
    targets = [
        (ELEMENT_DIR.glob("*.c"), OUT_DIR_ELEM, "bc_"),
        ((p for p in TASKLIST_ROOT.glob("*.c") if p.parent.name != "elements"), OUT_DIR_TASK, "bc_"),
        (TRANSITION_DIR.glob("*.c"), OUT_DIR_TRANS, "bc_"),
        (NORMAL_BC_DIR.glob("*.c"), OUT_DIR_NORMAL_BC, ""),  # nbc_xxx.c -> nbc_xxx.csv
    ]
    for files, out_dir, prefix in targets:
        for c_file in sorted(files):
            out = write_csv_for_file(c_file, out_dir, prefix)
            generated.append(out)
    print("generated CSVs:")
    for p in generated:
        print(" -", p.relative_to(ROOT))


if __name__ == "__main__":
    main()
