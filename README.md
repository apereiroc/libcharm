# Charm libc

Indeed, `charm` is yet another implementation of the C standard library.

The OSes where this library is tested during its development are macOS with both Intel and M1 chips, and Linux (through Docker containers).

Therefore, only macOS/Linux under `x86_64` and `arm64` architectures are currently supported.

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

You can also run the executable through the build system

```bash
scons -Q run
```


### Build options

The build system accepts optimisation mode (only `debug` and `release` are supported) and compiler selection (only `gcc` and `clang` are supported). The default for the build type is `debug`, while the compiler default is autodetected (`gcc` for Linux and `clang` for macOS).

```bash
scons --build=<{debug,release}> --compiler=<{gcc,clang}>
```

## Build and run in a Docker container

Build the ci image (minimal) with

```bash
docker buildx build -f Dockerfile.ci -t libcharm .
```

Compile the library with

```bash
docker run --rm -it -v $(pwd):/src -t libcharm scons --build=release
```

Run the main executable with

```bash
docker run --rm -it -v $(pwd):/src -t libcharm sh -c './target/linux-$(uname -m)-gcc-release/main'
```

Run the tests with

```bash
docker run --rm -it -v $(pwd):/src -t libcharm scons test
```

## Aliases for quick development

```bash
alias dbuild="docker buildx build --platform linux/amd64 -f Dockerfile.ci -t libcharm-dev ."
alias scons="docker run --platform linux/amd64 --rm -it -v $(pwd):/src libcharm-dev scons"
alias run="docker run --platform linux/amd64 --rm -it -v $(pwd):/src libcharm-dev"
```

# TODO List

## Testing lib
- [x] add testing framework
- [ ] provide tests for implemented functions

## Implement C runtime
- ... more todos

## Asynchronous input/output (`aio.h`)
- ... more todos

## Internet operations (`arpa/inet.h`)
- ... more todos

## Assertions (`assert.h`)
- [ ] assert macro (unimplemented, untested)

## Complex numbers (`complex.h`)
- ... more todos

## cpio archive values (`cpio.h`)
- ... more todos

## Character handling (`ctype.h`)
- ... more todos

## Format of directory entries (`dirent.h`)
- ... more todos

## Dynamic linking (`dlfcn.h`)
- [ ] `RTLD_LAZY` (undefined)
- [ ] `RTLD_NOW` (undefined)
- [ ] `RTLD_GLOBAL` (undefined)
- [ ] `RTLD_LOCAL` (undefined)
- [ ] `dlclose` (unimplemented, untested)
- [ ] `dlerror` (unimplemented, untested)
- [ ] `dlopen` (unimplemented, untested)
- [ ] `dlsym` (unimplemented, untested)
- [ ] `Dl_info` ??

## Error handling (`errno.h`)
- [ ] `errno` (implement as a thread-local variable) (unimplemented, untested)
- [ ] `provide error codes` (`EPERM`, `ENOMEM`, etc.) (unimplemented, untested)
- ... more todos

## File control options  (`fcntl.h`)
- ... more todos

## Floating-point environment  (`fenv.h`)
- ... more todos

## Floating-point types  (`float.h`)
- ... more todos

## Message display structures  (`fmtmsg.h`)
- [ ] `MM_HARD` (undefined)
- [ ] `MM_SOFT` (undefined)
- [ ] `MM_FIRM` (undefined)
- [ ] `MM_APPL` (undefined)
- [ ] `MM_UTIL` (undefined)
- [ ] `MM_OPSYS` (undefined)
- [ ] `MM_RECOVER` (undefined)
- [ ] `MM_NRECOV` (undefined)
- [ ] `MM_HALT` (undefined)
- [ ] `MM_ERROR` (undefined)
- [ ] `MM_WARNING` (undefined)
- [ ] `MM_INFO` (undefined)
- [ ] `MM_NOSEV` (undefined)
- [ ] `MM_PRINT` (undefined)
- [ ] `MM_CONSOLE` (undefined)
- [ ] `MM_NULLLBL` (undefined)
- [ ] `MM_NULLSEV` (undefined)
- [ ] `MM_NULLMC` (undefined)
- [ ] `MM_NULLTXT` (undefined)
- [ ] `MM_NULLACT` (undefined)
- [ ] `MM_NULLTAG` (undefined)
- [ ] `MM_OK` (undefined)
- [ ] `MM_NOTOK` (undefined)
- [ ] `MM_NOMSG` (undefined)
- [ ] `MM_NOCON` (undefined)
- [ ] `fmtmsg` (unimplemented, untested)

## Filename-matching types  (`fnmatch.h`)
- [ ] `FNM_NOMATCH` (undefined)
- [ ] `FNM_PATHNAME` (undefined)
- [ ] `FNM_PERIOD` (undefined)
- [ ] `FNM_NOESCAPE` (undefined)
- [ ] `FNM_IGNORECASE` ??
- [ ] `FNM_CASEFOLD` ??
- [ ] `FNM_FILE_NAME` ??
- [ ] `fnmatch` (unimplemented, untested)

## File tree traversal  (`ftw.h`)
- [ ] `FTW` (undefined)
- [ ] `FTW_` (undefined)
- [ ] `FTW_D` (undefined)
- [ ] `FTW_DNR` (undefined)
- [ ] `FTW_DP` (undefined)
- [ ] `FTW_NS` (undefined)
- [ ] `FTW_SL` (undefined)
- [ ] `FTW_SLN` (undefined)
- [ ] `FTW_PHYS` (undefined)
- [ ] `FTW_MOUNT` (undefined)
- [ ] `FTW_DEPTH` (undefined)
- [ ] `FTW_CHDIR` (undefined)
- [ ] `ftw` (unimplemented, untested)
- [ ] `nftw` (unimplemented, untested)
- [ ] `sys/stat.h`  (undefined)

## Pathname pattern-matching  (`glob.h`)
- [ ] `glob_t` (undefined)
- [ ] `size_t` (undefined)
- [ ] `GLOB_APPEND` (undefined)
- [ ] `GLOB_DOOFS` (undefined)
- [ ] `GLOB_ERR` (undefined)
- [ ] `GLOB_MARK` (undefined)
- [ ] `GLOB_NOCHECK` (undefined)
- [ ] `GLOB_NOESCAPE` (undefined)
- [ ] `GLOB_NOSORT` (undefined)
- [ ] `GLOB_ABORTED` (undefined)
- [ ] `GLOB_NOSPACE` (undefined)
- [ ] `glob` (unimplemented, untested)
- [ ] `globfree` (unimplemented, untested)

## Group structure  (`grp.h`)
- ... more todos

## Codeset conversion facility  (`iconv.h`)
- ... more todos

## Format conversion of integer types  (`inttypes.h`)
- ... more todos

## Alternative spellings  (`iso646.h`)
- ... more todos

## Language information constants  (`langinfo.h`)
- ... more todos

## Pattern matching functions  (`libgen.h`)
- ... more todos

## Sizes of integer types  (`limits.h`)
- ... more todos

## Localisation utils  (`locale.h`)
- ... more todos

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
- ... more todos

## Monetary types  (`monetary.h`)
- ... more todos

## Message queues  (`mqueue.h`)
- ... more todos

## Sockets local interfaces  (`net/if.h`)
- ... more todos

## Network database operations  (`netdb.h`)
- ... more todos

## Internet address family  (`netinet/in.h`)
- ... more todos

## Definitions for Transmission Control Protocol  (`netinet/tcp.h`)
- ... more todos

## Data types  (`nl_types.h`)
- ... more todos

## Poll function and definitions  (`poll.h`)
- ... more todos

## POSIX threads (`pthread.h`)
- [ ] `pthread_cond_signal` (unimplemented, untested)
- [ ] `pthread_cond_wait` (unimplemented, untested)
- [ ] `pthread_create` (unimplemented, untested)
- [ ] `pthread_exit` (unimplemented, untested)
- [ ] `pthread_join` (unimplemented, untested)
- [ ] `pthread_mutex_init` (unimplemented, untested)
- [ ] `pthread_mutex_lock` (unimplemented, untested)
- [ ] `pthread_mutex_unlock` (unimplemented, untested)
- ... more todos

## Password structure (`pwd.h`)
- ... more todos

## Regular expressions (`regex.h`)
- ... more todos

## Execution scheduling (`sched.h`)
- ... more todos

## Search tables (`search.h`)
- ... more todos

## Semaphores (`semaphore.h`)
- ... more todos

## Stack environment declarations  (`setjmp.h`)
- ... more todos

## Signal handling  (`signal.h`)
- ... more todos

## Spawn (advanced realtime)  (`spawn.h`)
- ... more todos

## Variable arguments  (`stdarg.h`)
- ... more todos

## Boolean types  (`stdbool.h`)
- [ ] `bool` (undefined)
- [ ] `true` (undefined)
- [ ] `false` (undefined)
- [ ] `__bool_true_false_are_defined` (undefined)

## Common definitions  (`stddef.h`)
- [ ] `NULL` (undefined)
- [ ] `offsetof` (unimplemented, untested)
- [ ] `ptrdiff_t` (undefined)
- [ ] `wchar_t` (undefined)
- [ ] `size_t` (undefined)
- [ ] `test: size no greater than long`  (untested)

## Fixed width integers (`stdint.h`)
- [ ] `test: check size at compile time` (undone)
- [x] `test: check size at runtime` (done)
- [x] `int8_t` (undefined)
- [x] `int16_t` (undefined)
- [x] `int32_t` (undefined)
- [x] `int64_t` (undefined)
- [x] `uint8_t` (undefined)
- [x] `uint16_t` (undefined)
- [x] `uint32_t` (undefined)
- [x] `uint64_t` (undefined)
- [x] `int_least8_t` (undefined)
- [x] `int_least16_t` (undefined)
- [x] `int_least32_t` (undefined)
- [x] `int_least64_t` (undefined)
- [x] `uint_least8_t` (undefined)
- [x] `uint_least16_t` (undefined)
- [x] `uint_least32_t` (undefined)
- [x] `uint_least64_t` (undefined)
- [x] `int_fast8_t` (undefined)
- [x] `int_fast16_t` (undefined)
- [x] `int_fast32_t` (undefined)
- [x] `int_fast64_t` (undefined)
- [x] `uint_fast8_t` (undefined)
- [x] `uint_fast16_t` (undefined)
- [x] `uint_fast32_t` (undefined)
- [x] `uint_fast64_t` (undefined)
- [x] `intptr_t` (undefined)
- [x] `uintptr_t` (undefined)
- [x] `intmax_t` (undefined)
- [x] `uintmax_t` (undefined)
- ... more todos

## Standard I/O (`stdio.h`)
- [ ] `FILE` (undefined)
- [ ] `fpos_t` (undefined)
- [ ] `off_t` (undefined)
- [ ] `size_t` (undefined)
- [ ] `ssize_t` (undefined)
- [ ] `va_list` (undefined)
- [ ] `BUFSIZ` (undefined)
- [ ] `L_ctermid` (undefined)
- [ ] `L_tmpnam` (undefined)
- [ ] `_IOFBF` (undefined)
- [ ] `_IOLBF` (undefined)
- [ ] `_IONBF` (undefined)
- [ ] `SEEK_CUR` (undefined)
- [ ] `SEEK_END` (undefined)
- [ ] `SEEK_SET` (undefined)
- [ ] `FILENAME_MAX` (undefined)
- [ ] `FOPEN_MAX` (undefined)
- [ ] `TMP_MAX` (undefined)
- [ ] `EOF` (undefined)
- [ ] `NULL` (undefined)
- [ ] `P_tmpdir` (undefined)
- [ ] `stdin` (undefined)
- [ ] `stdout` (undefined)
- [ ] `stderr` (undefined)
- [ ] `clearerr` (unimplemented, untested)
- [ ] `ctermid` (unimplemented, untested)
- [ ] `dprintf` (unimplemented, untested)
- [ ] `fclose` (unimplemented, untested)
- [ ] `fdopen` (unimplemented, untested)
- [ ] `feof` (unimplemented, untested)
- [ ] `ferror` (unimplemented, untested)
- [ ] `fflush` (unimplemented, untested)
- [ ] `fgetc` (unimplemented, untested)
- [ ] `fgetpos` (unimplemented, untested)
- [ ] `fgets` (unimplemented, untested)
- [ ] `fileno` (unimplemented, untested)
- [ ] `flockfile` (unimplemented, untested)
- [ ] `fmemopen` (unimplemented, untested)
- [ ] `fopen` (unimplemented, untested)
- [ ] `fprintf` (unimplemented, untested)
- [ ] `fputc` (unimplemented, untested)
- [ ] `fputs` (unimplemented, untested)
- [ ] `fread` (unimplemented, untested)
- [ ] `freopen` (unimplemented, untested)
- [ ] `fropen` (unimplemented, untested)
- [ ] `fscanf` (unimplemented, untested)
- [ ] `fseek` (unimplemented, untested)
- [ ] `fseeko` (unimplemented, untested)
- [ ] `fsetpos` (unimplemented, untested)
- [ ] `ftell` (unimplemented, untested)
- [ ] `ftello` (unimplemented, untested)
- [ ] `ftrylockfile` (unimplemented, untested)
- [ ] `funlockfile` (unimplemented, untested)
- [ ] `fwrite` (unimplemented, untested)
- [ ] `getc` (unimplemented, untested)
- [ ] `getchar` (unimplemented, untested)
- [ ] `getc_unlocked` (unimplemented, untested)
- [ ] `getchar_unlocked` (unimplemented, untested)
- [ ] `getdelim` (unimplemented, untested)
- [ ] `getline` (unimplemented, untested)
- [ ] `gets` (unimplemented, untested)
- [ ] `open_memstream` (unimplemented, untested)
- [ ] `pclose` (unimplemented, untested)
- [ ] `perror` (unimplemented, untested)
- [ ] `popen` (unimplemented, untested)
- [ ] `printf` (unimplemented, untested)
- [ ] `putc` (unimplemented, untested)
- [ ] `putchar` (unimplemented, untested)
- [ ] `putc_unlocked` (unimplemented, untested)
- [ ] `putchar_unlocked` (unimplemented, untested)
- [x] `puts` (implemented, untested)
- [ ] `remove` (unimplemented, untested)
- [ ] `rename` (unimplemented, untested)
- [ ] `renameat` (unimplemented, untested)
- [ ] `rewind` (unimplemented, untested)
- [ ] `scanf` (unimplemented, untested)
- [ ] `setbuf` (unimplemented, untested)
- [ ] `setvbuf` (unimplemented, untested)
- [ ] `snprintf` (unimplemented, untested)
- [ ] `sprintf` (unimplemented, untested)
- [ ] `sscanf` (unimplemented, untested)
- [ ] `tempnam` (unimplemented, untested)
- [ ] `tmpfile` (unimplemented, untested)
- [ ] `tmpnam` (unimplemented, untested)
- [ ] `ungetc` (unimplemented, untested)
- [ ] `vdprintf` (unimplemented, untested)
- [ ] `vfprintf` (unimplemented, untested)
- [ ] `vfscanf` (unimplemented, untested)
- [ ] `vprintf` (unimplemented, untested)
- [ ] `vscanf` (unimplemented, untested)
- [ ] `vsnprintf` (unimplemented, untested)
- [ ] `vsscanf` (unimplemented, untested)

## General-purpose functions and utilities (`stdlib.h`)
- [ ] `brk`/`sbrk` system call wrappers (unimplemented, untested)
- [ ] `calloc` (unimplemented, untested)
- [ ] `free` (unimplemented, untested)
- [ ] `malloc` (unimplemented, untested)
- [ ] `realloc` (unimplemented, untested)
- [ ] `exit` (implemented, untested)
- [ ] `atexit` (unimplemented, untested)
- [ ] `getenv` (unimplemented, untested)
- [ ] `setenv` (unimplemented, untested)
- [ ] `system` (unimplemented, untested)
- [ ] `unsetenv` (unimplemented, untested)
- ... more todos

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
- ... more todos

## More string handling (`strings.h`)
- ... more todos

## Streams interace (`stropts.h`)
- ... more todos

## Interprocess communications (`sys/ipc.h`)
- ... more todos

## Memory management (`sys/mman.h`)
- ... more todos

## Message queues  (`sys/msg.h`)
- ... more todos

## Resource operations  (`sys/resource.h`)
- ... more todos

## Select types  (`sys/select.h`)
- ... more todos

## Semaphore facility  (`sys/sem.h`)
- ... more todos

## Shared memory facility  (`sys/shm.h`)
- ... more todos

## Sockets  (`sys/socket.h`)
- ... more todos

## File status (stat and friends)  (`sys/stat.h`)
- ... more todos

## Filesystem statistics  (`sys/statvfs.h`)
- ... more todos

## Time types (`sys/time.h`)
- ... more todos

## File acess and modification times  (`sys/times.h`)
- ... more todos

## Data types  (`sys/types.h`)
- ... more todos

## Vector I/O ops  (`sys/uio.h`)
- ... more todos

## Unix domain sockets  (`sys/un.h`)
- ... more todos

## System structure name  (`sys/utsname.h`)
- ... more todos

## Waiting  (`sys/wait.h`)
- ... more todos

## System error logging  (`sys/syslog.h`)
- ... more todos

## Tar defs  (`tar.h`)
- ... more todos

## Terminal I/O  (`termios.h`)
- ... more todos

## Type generic math (`tgmath.h`)
- ... more todos

## Date and time (`time.h`)
- [ ] `clock` (unimplemented, untested)
- [ ] `gettimeofday` (unimplemented, untested)
- [ ] `gmtime` (unimplemented, untested)
- [ ] `localtime` (unimplemented, untested)
- [ ] `mktime` (unimplemented, untested)
- [ ] `settimeofday` (unimplemented, untested)
- [ ] `strftime` (unimplemented, untested)
- [ ] `time` (unimplemented, untested)
- ... more todos

## Tracing (`trace.h`)
- ... more todos

## Ulimit commands (`ulimit.h`)
- ... more todos

## Standard constants/types and miscellaneous functions (`unistd.h`)
- ... more todos

## Access and modification time (`utime.h`)
- ... more todos

## User accounting database (`utmpx.h`)
- ... more todos

## Wide character utilities (`wchar.h`)
- ... more todos

## Wide character classification (`wctype.h`)
- ... more todos

## Word-expansion types (`wordexp.h`)
- ... more todos
