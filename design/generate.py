from pathlib import Path

import c2a_generator
import importlib.metadata

root_path = (
    Path(__file__).parent.parent
)

# eh
c2a_generator.eh_rules_h.generate(
    root_path / "design/eh.csv",
    root_path / "src/src_user/settings/system/event_handler_rules/event_handler_rules.h",
    base_id=0,
)
c2a_generator.eh_rules_c.generate(
    root_path / "design/eh.csv",
    root_path / "src/src_user/settings/system/event_handler_rules/event_handler_rules.c",
    eh_header="""
#include "event_handler_rules.h"
#include <src_core/system/event_manager/event_handler.h>
#include "../../../tlm_cmd/block_command_definitions.h"
#include "../../../tlm_cmd/block_command_definitions.h"
""",
)
include_cmd_def = """
#include <src_core/tlm_cmd/command_analyze.h>
#include "command_definitions.h"
#include "command_source.h"
"""[1:]
# cmd
c2a_generator.cmd_def_c.generate(
    root_path / "design/cmd.csv",
    include_cmd_def,
    root_path / "src/src_user/tlm_cmd/command_definitions.c",
)
c2a_generator.cmd_def_h.generate(
    root_path / "design/cmd.csv",
    root_path / "src/src_user/tlm_cmd/command_definitions.h",
)
c2a_generator.cmd_csv.generate(
    root_path / "design/cmd.csv",
    root_path / "tlm-cmd-db/CMD_DB/AOBC_CMD_DB_CMD_DB.csv",
    "AOBC",
)

# bct
bct_sl_src = [
    [root_path / "design/bct/transitions/sl_initial.csv", 0],
]
bct_tl_src = [
    [root_path / "design/bct/task_lists/tl_start_up.csv", 10],
    [root_path / "design/bct/task_lists/tl_initial.csv", 11],
]
bct_tl_elem_src = [
    [root_path / "design/bct/task_lists/elements/tl_elem_debug_display.csv", 17],
    [root_path / "design/bct/task_lists/elements/tl_elem_cdh_update.csv", 19],
    [root_path / "design/bct/task_lists/elements/tl_elem_tlm_cmd_hirate.csv", 50],
]
bct_nbc_src = [
    [root_path / "design/bct/normal_block_command_definition/nbc_start_hk_tlm.csv", 60],
    [root_path / "design/bct/normal_block_command_definition/nbc_stim377h.csv", 70],
]

include_bc_def = """
#include "block_command_definitions.h"
#include <src_core/tlm_cmd/block_command_loader.h>
#include <src_core/tlm_cmd/block_command_table.h>
#include <src_core/system/watchdog_timer/watchdog_timer.h>
#include <string.h>
#include "command_definitions.h"
#include "./normal_block_command_definition/nbc_header.h"
"""[1:]
include_nbc_header = """
#include "../block_command_definitions.h"
#include <src_core/tlm_cmd/block_command_loader.h>
#include <src_core/tlm_cmd/block_command_table.h>
#include <string.h> // for memcpy
#include "../command_definitions.h"
#include "src_user/settings/system/event_handler_rules/event_handler_rules.h"
#include "src_user/settings/system/event_logger_group.h"
"""[1:]
include_each_bc_def = """
#include "nbc_header.h"
#include "../telemetry_definitions.h"
"""[1:]

for bct in bct_sl_src:
    stem = bct[0].stem
    include_each_bc_def_sl = f"""
#include "{stem}.h"

#include <src_user/tlm_cmd/block_command_definitions.h>
#include <src_user/tlm_cmd/command_definitions.h>

#include <src_core/applications/timeline_command_dispatcher_id_define.h>
#include <src_core/tlm_cmd/block_command_loader.h>
#include <src_core/system/time_manager/obc_time.h>
"""[1:]
    c2a_generator.bct_def_c.generate(
        [bct],
        root_path / "src/src_user/tlm_cmd/block_command_definitions.c",
        root_path / "src/src_user/settings/modes/transitions" / f"{stem}.h",
        include_bc_def,
        include_each_bc_def_sl,
        "",
    )

for bct in bct_tl_src:
    stem = bct[0].stem
    include_each_bc_def_tl = f"""
#include "{stem}.h"

#include <src_user/applications/app_registry.h>
#include <src_user/tlm_cmd/block_command_definitions.h>

#include <src_core/tlm_cmd/block_command_loader.h>
"""[1:]
    c2a_generator.bct_def_c.generate(
        [bct],
        root_path / "src/src_user/tlm_cmd/block_command_definitions.c",
        root_path / "src/src_user/settings/modes/task_lists" / f"{stem}.h",
        include_bc_def,
        include_each_bc_def_tl,
        "",
    )

for bct in bct_tl_elem_src:
    stem = bct[0].stem
    include_each_bc_def_tl_elem = f"""
#include "{stem}.h"

#include <src_user/applications/app_registry.h>
#include <src_user/tlm_cmd/block_command_definitions.h>

#include <src_core/tlm_cmd/block_command_loader.h>
"""[1:]
    c2a_generator.bct_def_c.generate(
        [bct],
        root_path / "src/src_user/tlm_cmd/block_command_definitions.c",
        root_path / "src/src_user/settings/modes/task_lists/elements" / f"{stem}.h",
        include_bc_def,
        include_each_bc_def_tl_elem,
        "",
    )

bct_src = bct_sl_src + bct_tl_src + bct_tl_elem_src + bct_nbc_src
c2a_generator.bct_def_c.generate(
    bct_src,
    root_path / "src/src_user/tlm_cmd/block_command_definitions.c",
    root_path / "src/src_user/tlm_cmd/bc_header_dummy.h",
    include_bc_def,
    include_each_bc_def,
    include_nbc_header,
)
c2a_generator.bct_def_h.generate(
    bct_src, root_path / "src/src_user/tlm_cmd/block_command_definitions.h"
)
c2a_generator.bct_csv.generate(
    bct_src, root_path / "tlm-cmd-db/CMD_DB/AOBC_CMD_DB_BCT.csv"
)
dummy_bc_header = root_path / "src/src_user/tlm_cmd/bc_header_dummy.h"
if dummy_bc_header.exists():
    dummy_bc_header.unlink()
for bct in bct_src:
    stem = bct[0].stem
    bc_header_path = root_path / "src/src_user/tlm_cmd/" / f"{stem}.c"
    if bc_header_path.exists():
        bc_header_path.unlink()

# tlm
tlm_path = root_path / "design/tlm"
c2a_generator.tlm_def_h.generate(
    tlm_path, root_path / "src/src_user/tlm_cmd/telemetry_definitions.h"
)
include_tlm_def = """
#include <src_core/tlm_cmd/telemetry_frame.h>
#include "telemetry_definitions.h"
#include "telemetry_source.h"
"""[1:]
c2a_generator.tlm_def_c.generate(
    tlm_path, 
    include_tlm_def,
    root_path / "src/src_user/tlm_cmd/telemetry_definitions.c"
)
c2a_generator.tlm_csv.generate(
    tlm_path, root_path / "tlm-cmd-db/TLM_DB", prefix="AOBC_TLM_DB_"
)

def remove_files_except_gitkeep(directory_path: Path) -> None:
    """
    指定したディレクトリ内のファイルを.gitkeepを除いて全て削除する
    """
    for item in directory_path.glob("*"):
        if item.is_file() and item.name != ".gitkeep":
            item.unlink()
    if not any(item.is_dir() or item.is_file() for item in directory_path.glob("*")):
        directory_path.rmdir()
