# Yet another implementation of the C standard library

## Build and run locally

The project is currently only built through SCons. If you have this build system install on your computer, just run
```bash
scons
```

and run the executable generated at the build folder

```bash
./target/{build-opts}/main
```

`build-opts` is a folder constructed by the information passed to the construction tool, namely `{compiler}-{optimisation}-{architecture}`. For example, on macOS with Intel chip the executable is determined to be at `./clang-debug-x86_64/main`. On the other hand, optimised compilation on Linux/arm64 is at `./target/gcc-release-arm64/main`.

## Build and run in a Docker container

In this example, the `x86_64` architecture will be fixed because of the output folder but feel free to use your native architecture

Build the image with

```bash
docker buildx build --platform linux/amd64 -t yalibc-dev .
```

Compile the library with

```bash
docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev scons --build=release
```

Run main executable with

```bash
docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev ./target/gcc-release-x86_64/main
```

## Aliases for quick development

```bash
alias build="docker buildx build --platform linux/amd64 -t yalibc-dev ."
alias scons="docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev scons"
alias run="docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev"
```

# TODO List

## Testing
- [ ] add testing framework
- [ ] provide tests for implemented functions

## String handling (`string.h`)
- [x] `strlen` (implemented, untested)
  - [ ] test
- [ ] `strcmp`
  - [ ] test
- [ ] `strncmp`
  - [ ] test
- [ ] `strcpy`
  - [ ] test
- [ ] `strncpy`
  - [ ] test
- [ ] `strcat`
  - [ ] test
- [ ] `strncat`
  - [ ] test
- [ ] `strchr`
  - [ ] test
- [ ] `strrchr`
  - [ ] test
- [ ] `strstr`
  - [ ] test
- [ ] `memcpy`
  - [ ] test
- [ ] `memmove`
  - [ ] test
- [ ] `memset`
  - [ ] test
- [ ] `memcmp`
  - [ ] test

## 2. Standard I/O (`stdio.h`)
- [x] `puts` (implemented, untested)
  - [ ] test
- [ ] `printf`
  - [ ] test
- [ ] `sprintf`
  - [ ] test
- [ ] `snprintf`
  - [ ] test
- [ ] `putchar`
  - [ ] test
- [ ] `getchar`
  - [ ] test
- [ ] `fopen`
  - [ ] test
- [ ] `fclose`
  - [ ] test
- [ ] `fread`
  - [ ] test
- [ ] `fwrite`
  - [ ] test
- [ ] `fprintf`
  - [ ] test
- [ ] `vfprintf`
  - [ ] test
- [ ] `fseek`
  - [ ] test
- [ ] `ftell`
  - [ ] test
- [ ] `rewind`
  - [ ] test
- [ ] `fgets`
  - [ ] test
- [ ] `fputs`
  - [ ] test

## 3. Memory Management (`stdlib.h`)
- [ ] `malloc`
  - [ ] test
- [ ] `free`
  - [ ] test
- [ ] `calloc`
  - [ ] test
- [ ] `realloc`
  - [ ] test
- [ ] `aligned_alloc`
  - [ ] test
- [ ] `brk`/`sbrk` system call wrappers
  - [ ] test

## 4. Process & System Calls (`unistd.h`, `sys/types.h`)
- [ ] `fork`
  - [ ] test
- [ ] `execve`
  - [ ] test
- [ ] `wait`
  - [ ] test
- [ ] `waitpid`
  - [ ] test
- [x] `exit` (implemented, untested)
  - [ ] test
- [ ] `_exit`
  - [ ] test
- [ ] `abort`
  - [ ] test
- [ ] `getpid`
  - [ ] test
- [ ] `getppid`
  - [ ] test
- [ ] `sleep`
  - [ ] test
- [ ] `usleep`
  - [ ] test
- [ ] `nanosleep`
  - [ ] test
- [ ] `chdir`
  - [ ] test
- [ ] `getcwd`
  - [ ] test
- [ ] `isatty`
  - [ ] test
- [ ] `kill`
  - [ ] test
- [ ] `signal`
  - [ ] test

## 5. File system, file descriptors (`fcntl.h`, `sys/stat.h`)
- [ ] `open`
  - [ ] test
- [ ] `close`
  - [ ] test
- [ ] `read`
  - [ ] test
- [x] `write` (implemented, untested)
  - [ ] test
- [ ] `lseek`
  - [ ] test
- [ ] `stat`
  - [ ] test
- [ ] `fstat`
  - [ ] test
- [ ] `lstat`
  - [ ] test
- [ ] `chmod`
  - [ ] test
- [ ] `chown`
  - [ ] test
- [ ] `dup`
  - [ ] test
- [ ] `dup2`
  - [ ] test
- [ ] `pipe`
  - [ ] test
- [ ] `mkdir`
  - [ ] test
- [ ] `rmdir`
  - [ ] test
- [ ] `unlink`
  - [ ] test

## 6. Time functions (`time.h`)
- [ ] `time`
  - [ ] test
- [ ] `clock`
  - [ ] test
- [ ] `gettimeofday`
  - [ ] test
- [ ] `settimeofday`
  - [ ] test
- [ ] `gmtime`
  - [ ] test
- [ ] `localtime`
  - [ ] test
- [ ] `mktime`
  - [ ] test
- [ ] `strftime`
  - [ ] test

## 7. Math stuff (`math.h`)
- [ ] `abs`
  - [ ] test
- [ ] `labs`
  - [ ] test
- [ ] `llabs`
  - [ ] test
- [ ] `pow`
  - [ ] test
- [ ] `sqrt`
  - [ ] test
- [ ] `exp`
  - [ ] test
- [ ] `log`
  - [ ] test
- [ ] `sin`
  - [ ] test
- [ ] `cos`
  - [ ] test
- [ ] `tan`
  - [ ] test
- [ ] `atan2`
  - [ ] test
- [ ] `ceil`
  - [ ] test
- [ ] `floor`
  - [ ] test
- [ ] `round`
  - [ ] test
- [ ] `rand`
  - [ ] test
- [ ] `srand`
  - [ ] test

## Error handling (`errno.h`)
- [ ] implement `errno` as a thread-local variable
  - [ ] test
- [ ] provide error codes (`EPERM`, `ENOMEM`, etc.)
  - [ ] test

## Threading/synchronization (`pthread.h`)
- [ ] `pthread_create`
  - [ ] test
- [ ] `pthread_exit`
  - [ ] test
- [ ] `pthread_join`
  - [ ] test
- [ ] `pthread_mutex_init`
  - [ ] test
- [ ] `pthread_mutex_lock`
  - [ ] test
- [ ] `pthread_mutex_unlock`
  - [ ] test
- [ ] `pthread_cond_wait`
  - [ ] test
- [ ] `pthread_cond_signal`
  - [ ] test

## Environment (`stdlib.h`)
- [ ] `getenv`
  - [ ] test
- [ ] `setenv`
  - [ ] test
- [ ] `unsetenv`
  - [ ] test
- [ ] `system`
  - [ ] test
- [ ] `atexit`
  - [ ] test
