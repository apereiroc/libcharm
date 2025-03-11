#pragma once

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

#if defined(__x86_64__) || defined(__aarch64__)
typedef long int64_t;
typedef unsigned long uint64_t;
#else
#error "Unsupported architecture"
#endif
