#pragma once

#include "stddef.h"

__attribute__((noreturn)) void _exit(int exit_code);

ssize_t write(int fildes, const void *buf, size_t nbyte);
