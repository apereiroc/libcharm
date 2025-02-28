# Yet another implementation of the C standard library

## Build

docker build -t yalibc .

## Run

Compile with

docker run --rm -it -v $(pwd):/src yalibc scons

Run with

docker run --rm -it -v $(pwd):/src yalibc ./main

## Aliases

alias scons="docker run --rm -it -v $(pwd):/src yalibc scons"
alias run="docker run --rm -it -v $(pwd):/src yalibc ./main"
