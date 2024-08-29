#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <atomic>

extern std::atomic_int fsync_period_count;
extern int fsync_period;

#endif // GLOBAL_H_
