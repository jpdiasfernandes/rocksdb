//  Copyright (c) 2013-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).
//
// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef GFLAGS
#include <cstdio>
int main() {
  fprintf(stderr, "Please install gflags to run rocksdb tools\n");
  return 1;
}
#else
#include "rocksdb/db_bench_tool.h"
#include <erm/repository.hpp>
#include "util/flags_log_file.h"
int main(int argc, char** argv) {
  int res = ROCKSDB_NAMESPACE::db_bench_tool(argc, argv);
  erm::Repository::dump_event_timeline_file(FLAGS_db_bench_erm_file, "root");
  return res;
}
#endif  // GFLAGS
