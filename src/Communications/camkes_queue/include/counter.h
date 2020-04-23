#pragma once

#include <stdint.h>

#ifdef __cplusplus
#include <atomic>
using namespace std;
#else
#include <stdatomic.h>
#endif

// Defs to allow easy changing of counter type. Keep these consistent!
typedef atomic_uintmax_t counter_t;
#define COUNTER_MAX UINTMAX_MAX
#define PRIcounter PRIuMAX
