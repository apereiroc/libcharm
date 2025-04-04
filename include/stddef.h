#pragma once

#include <stdint.h>

#if defined(__x86_64__) || defined(__aarch64__)
typedef uint64_t size_t;
typedef int64_t ssize_t;
#else
#error "Unsupported architecture"
#endif

// Define NULL manually
#define NULL ((void *)0)
