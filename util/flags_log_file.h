#pragma once
#include <gflags/gflags.h>

DEFINE_string(compaction_erm_file, "compaction.log", "The compaction log file that erm uses to dump compaction events.");
DEFINE_string(db_bench_erm_file, "all_events.log", "Full record of all the events that erm captured throughout "
              "the execution of db_bench");
DEFINE_string(flush_erm_file, "flush.log", "The flush log file that erm uses to dump flush events.");
