#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import csv
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SRC = ROOT / "src" / "src_user" / "settings" / "system" / "event_handler_rules" / "event_handler_rule_sw_oc.c"
OUT_DIR = ROOT / "design" / "eh"
OUT = OUT_DIR / "eh_sw_oc.csv"
FDIR_IMPL = ROOT / "src" / "src_user" / "settings" / "SatelliteParameters" / "Sample" / "fdir_parameters.c"

HEADERS = [
    "subsystem", "is_active", "name", "group", "local", "err_level",
    "should_match_err_level", "type", "count_threshold", "time_threshold[s]",
    "bc", "description", "note"
]

# ---- 解析ヘルパ ----
assign_re = re.compile(r"settings\.(event\.group|event\.local|event\.err_level|should_match_err_level|"
                       r"condition\.type|condition\.count_threshold|condition\.time_threshold_ms|"
                       r"deploy_bct_id|is_active)\s*=\s*([^;]+);")
register_re = re.compile(r"EH_register_rule\(\s*([A-Za-z0-9_]+)\s*,")

# シンプルな定数値探索用: "const uint32_t NAME = 5000;" のような行から数値を拾う
const_def_re = re.compile(r"(?:const\s+\w+\s+)?(?P<name>[A-Za-z0-9_]+)\s*=\s*(?P<val>[0-9]+)\s*;")


def conv_bool(val: str) -> str:
    val = val.strip()
    if val in ("1", "true", "TRUE"):
        return "TRUE"
    if val in ("0", "false", "FALSE"):
        return "FALSE"
    return val  # そのまま返す（定数名など）


def conv_err_level(val: str) -> str:
    v = val.strip()
    if v.startswith("EL_ERROR_LEVEL_"):
        return v.replace("EL_ERROR_LEVEL_", "")
    return v


def conv_type(val: str) -> str:
    v = val.strip()
    if v.startswith("EH_RESPONSE_CONDITION_"):
        return v.replace("EH_RESPONSE_CONDITION_", "")
    return v


def conv_time_ms_to_s(val: str) -> str:
    v = val.strip()
    # 数値リテラルなら 1000 で割る
    if re.fullmatch(r"\d+", v):
        return str(int(v) / 1000)
    # 定数名を実装ファイルから引く
    looked = lookup_const_numeric(v)
    if looked is not None:
        return str(looked / 1000)
    # 変換不能な場合は "0" にフォールバックして generator の float 変換エラーを回避
    return "0"


def lookup_const_numeric(name: str):
    if not FDIR_IMPL.exists():
        return None
    text = FDIR_IMPL.read_text(encoding="utf-8")
    for m in const_def_re.finditer(text):
        if m.group("name") == name:
            try:
                return int(m.group("val"))
            except ValueError:
                return None
    return None


def parse_rules(text: str):
    records = []
    current = {}
    current_note = ""
    for line in text.splitlines():
        stripped = line.strip()
        # 空行で note をクリア（前のコメントが次セクションへ引き継がれるのを防ぐ）
        if stripped == "":
            current_note = ""
            continue
        # セクション先頭の `// ...` コメントを note として保持する
        if stripped.startswith("//"):
            comment = stripped[2:].strip()
            if comment:
                current_note = f"{current_note} / {comment}" if current_note else comment
            continue
        # コメント以外で、設定代入や登録行でもない場合は note をリセットする
        # これにより include などの前置コメントが後段のルールに紐づかないようにする
        if stripped and not assign_re.search(line) and not register_re.search(line):
            current_note = ""

        m = assign_re.search(line)
        if m:
            key, rhs = m.group(1), m.group(2)
            current[key] = rhs.strip()
            continue
        reg = register_re.search(line)
        if reg:
            name = reg.group(1)
            rec = {
                "subsystem": "*",
                "is_active": conv_bool(current.get("is_active", "0")),
                "name": name,
                "group": current.get("event.group", ""),
                "local": current.get("event.local", ""),
                "err_level": conv_err_level(current.get("event.err_level", "")),
                "should_match_err_level": conv_bool(current.get("should_match_err_level", "")),
                "type": conv_type(current.get("condition.type", "")),
                "count_threshold": current.get("condition.count_threshold", ""),
                "time_threshold[s]": conv_time_ms_to_s(current.get("condition.time_threshold_ms", "")),
                "bc": current.get("deploy_bct_id", ""),
                "description": "",
                "note": current_note,
            }
            records.append(rec)
            current = {}
            current_note = ""
    return records


def main():
    text = SRC.read_text(encoding="utf-8")
    records = parse_rules(text)
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    with OUT.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=HEADERS)
        writer.writeheader()
        for r in records:
            writer.writerow(r)


if __name__ == "__main__":
    main()
