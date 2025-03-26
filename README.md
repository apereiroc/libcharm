# Yet another implementation of the C standard library

You got it right. 

The OSes where this library is tested during its development are macOS with both Intel (x86_64) and M1 (arm64) chips, and Linux (through Docker containers) for both platforms as well.

## Build and run locally

The project is, for now, built with `SCons`. If you have this build system installed in your computer, just run
```bash
scons
```


Run the executable generated at the build folder
```bash
./target/{build-opts}/main
```

where `build-opts` is a folder constructed with the information passed to the construction tool, namely `{os}-{architecture}-{compiler}-{optimisation}`. For example, on macOS with Intel chip the executable is determined to be at `./darwin-x86_64-clang-debug/main`. On the other hand, optimised compilation on Linux/arm64 is at `./target/linux-arm64-gcc-release/main`

### Build options

The build system accepts optimisation mode (only `debug` and `release` are supported) and compiler selection (only `gcc` and `clang` are supported). The default for the build type is `debug`, while the compiler default is autodetected (`gcc` for Linux and `clang` for macOS).
```bash
scons --build=<{debug,release}> --compiler=<{gcc,clang}>
```


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
docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev ./target/linux-x86_64-gcc-release/main
```

## Aliases for quick development

```bash
alias build="docker buildx build --platform linux/amd64 -t yalibc-dev ."
alias scons="docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev scons"
alias run="docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev"
```

# TODO List

## Testing
- [x] add testing framework
- [ ] provide tests for implemented functions

## Assertions (`assert.h`)
- [ ] assert macro (unimplemented)

## String handling (`string.h`)
- [ ] `memchr` (unimplemented, untested)
- [ ] `memcmp` (unimplemented, untested)
- [ ] `memcpy` (unimplemented, untested)
- [ ] `memmove` (unimplemented, untested)
- [ ] `memset` (unimplemented, untested)
- [ ] `strcat` (unimplemented, untested)
- [ ] `strchr` (unimplemented, untested)
- [ ] `strcmp` (unimplemented, untested)
- [ ] `strcpy` (unimplemented, untested)
- [ ] `strncat` (unimplemented, untested)
- [ ] `strncmp` (unimplemented, untested)
- [ ] `strncpy` (unimplemented, untested)
- [ ] `strrchr` (unimplemented, untested)
- [x] `strlen` (implemented, tested)
- [ ] `strstr` (unimplemented, untested)

## Standard I/O (`stdio.h`)
- [ ] `clearerr` (unimplemented, untested)
- [ ] `fclose` (unimplemented, untested)
- [ ] `fdopen` (unimplemented, untested)
- [ ] `feof` (unimplemented, untested)
- [ ] `ferror` (unimplemented, untested)
- [ ] `fflush` (unimplemented, untested)
- [ ] `fgetc` (unimplemented, untested)
- [ ] `fgetpos` (unimplemented, untested)
- [ ] `fgets` (unimplemented, untested)
- [ ] `fopen` (unimplemented, untested)
- [ ] `fprintf` (unimplemented, untested)
- [ ] `fputc` (unimplemented, untested)
- [ ] `fputs` (unimplemented, untested)
- [ ] `fread` (unimplemented, untested)
- [ ] `freopen` (unimplemented, untested)
- [ ] `fropen` (unimplemented, untested)
- [ ] `fscanf` (unimplemented, untested)
- [ ] `fseek` (unimplemented, untested)
- [ ] `fsetpos` (unimplemented, untested)
- [ ] `ftell` (unimplemented, untested)
- [ ] `fwrite` (unimplemented, untested)
- [ ] `getc` (unimplemented, untested)
- [ ] `getchar` (unimplemented, untested)
- [ ] `gets` (unimplemented, untested)
- [ ] `perror` (unimplemented, untested)
- [ ] `printf` (unimplemented, untested)
- [ ] `putc` (unimplemented, untested)
- [ ] `putchar` (unimplemented, untested)
- [x] `puts` (implemented, untested)
- [ ] `remove` (unimplemented, untested)
- [ ] `rename` (unimplemented, untested)
- [ ] `rewind` (unimplemented, untested)
- [ ] `scanf` (unimplemented, untested)
- [ ] `setbuf` (unimplemented, untested)
- [ ] `setvbuf` (unimplemented, untested)
- [ ] `snprintf` (unimplemented, untested)
- [ ] `sprintf` (unimplemented, untested)
- [ ] `sscanf` (unimplemented, untested)
- [ ] `tmpfile` (unimplemented, untested)
- [ ] `tmpnam` (unimplemented, untested)
- [ ] `ungetc` (unimplemented, untested)
- [ ] `vfprintf` (unimplemented, untested)
- [ ] `vfscanf` (unimplemented, untested)
- [ ] `vprintf` (unimplemented, untested)
- [ ] `vscanf` (unimplemented, untested)
- [ ] `vsnprintf` (unimplemented, untested)
- [ ] `vsscanf` (unimplemented, untested)

## Memory Management (`stdlib.h`)
- [ ] `aligned_alloc` (unimplemented, untested)
- [ ] `brk`/`sbrk` system call wrappers (unimplemented, untested)
- [ ] `calloc` (unimplemented, untested)
- [ ] `free` (unimplemented, untested)
- [ ] `malloc` (unimplemented, untested)
- [ ] `realloc` (unimplemented, untested)
- [ ] `exit` (implemented, untested)

## Process & System Calls (`unistd.h`, `sys/types.h`)
- [ x ] `_exit` (implemented, untested)
- [ ] `abort` (unimplemented, untested)
- [ ] `chdir` (unimplemented, untested)
- [ ] `execve` (unimplemented, untested)
- [ ] `fork` (unimplemented, untested)
- [ ] `getcwd` (unimplemented, untested)
- [ ] `getpid` (unimplemented, untested)
- [ ] `getppid` (unimplemented, untested)
- [ ] `isatty` (unimplemented, untested)
- [ ] `kill` (unimplemented, untested)
- [ ] `nanosleep` (unimplemented, untested)
- [ ] `signal` (unimplemented, untested)
- [ ] `sleep` (unimplemented, untested)
- [ ] `usleep` (unimplemented, untested)
- [ ] `wait` (unimplemented, untested)
- [ ] `waitpid` (unimplemented, untested)

## File system, file descriptors (`fcntl.h`, `sys/stat.h`)
- [ ] `chmod` (unimplemented, untested)
- [ ] `chown` (unimplemented, untested)
- [ ] `close` (unimplemented, untested)
- [ ] `dup` (unimplemented, untested)
- [ ] `dup2` (unimplemented, untested)
- [ ] `fstat` (unimplemented, untested)
- [ ] `lseek` (unimplemented, untested)
- [ ] `lstat` (unimplemented, untested)
- [ ] `mkdir` (unimplemented, untested)
- [ ] `open` (unimplemented, untested)
- [ ] `pipe` (unimplemented, untested)
- [ ] `read` (unimplemented, untested)
- [ ] `rmdir` (unimplemented, untested)
- [ ] `stat` (unimplemented, untested)
- [ ] `unlink` (unimplemented, untested)
- [x] `write` (implemented, untested)

## Time functions (`time.h`)
- [ ] `clock` (unimplemented, untested)
- [ ] `gettimeofday` (unimplemented, untested)
- [ ] `gmtime` (unimplemented, untested)
- [ ] `localtime` (unimplemented, untested)
- [ ] `mktime` (unimplemented, untested)
- [ ] `settimeofday` (unimplemented, untested)
- [ ] `strftime` (unimplemented, untested)
- [ ] `time` (unimplemented, untested)

## Math stuff (`math.h`)
- [ ] `abs` (unimplemented, untested)
- [ ] `atan2` (unimplemented, untested)
- [ ] `ceil` (unimplemented, untested)
- [ ] `cos` (unimplemented, untested)
- [ ] `exp` (unimplemented, untested)
- [ ] `floor` (unimplemented, untested)
- [ ] `labs` (unimplemented, untested)
- [ ] `llabs` (unimplemented, untested)
- [ ] `log` (unimplemented, untested)
- [ ] `pow` (unimplemented, untested)
- [ ] `rand` (unimplemented, untested)
- [ ] `round` (unimplemented, untested)
- [ ] `sin` (unimplemented, untested)
- [ ] `sqrt` (unimplemented, untested)
- [ ] `srand` (unimplemented, untested)
- [ ] `tan` (unimplemented, untested)

## Error handling (`errno.h`)
- [ ] `errno` (implement as a thread-local variable) (unimplemented, untested)
- [ ] `provide error codes` (`EPERM`, `ENOMEM`, etc.) (unimplemented, untested)

## Threading/synchronization (`pthread.h`)
- [ ] `pthread_cond_signal` (unimplemented, untested)
- [ ] `pthread_cond_wait` (unimplemented, untested)
- [ ] `pthread_create` (unimplemented, untested)
- [ ] `pthread_exit` (unimplemented, untested)
- [ ] `pthread_join` (unimplemented, untested)
- [ ] `pthread_mutex_init` (unimplemented, untested)
- [ ] `pthread_mutex_lock` (unimplemented, untested)
- [ ] `pthread_mutex_unlock` (unimplemented, untested)

## Environment (`stdlib.h`)
- [ ] `atexit` (unimplemented, untested)
- [ ] `getenv` (unimplemented, untested)
- [ ] `setenv` (unimplemented, untested)
- [ ] `system` (unimplemented, untested)
- [ ] `unsetenv` (unimplemented, untested)
