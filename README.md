# Yet another implementation of the C standard library

## Build

```bash
docker buildx build --platform linux/amd64 -t yalibc-dev .
```

## Run

Compile with

```bash
docker run --rm -it -v $(pwd):/src yalibc-dev scons
```

Run with
```bash
docker run --rm -it -v $(pwd):/src yalibc-dev ./main-gcc-dbg
```

## Aliases for quick development

```bash
alias build="docker buildx build --platform linux/amd64 -t yalibc-dev ."
alias scons="docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev scons"
alias run="docker run --platform linux/amd64 --rm -it -v $(pwd):/src yalibc-dev"
```
