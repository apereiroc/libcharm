# Yet another implementation of the C standard library

## Build

docker build -t yalibc-dev .

## Run

Compile with

docker run --rm -it -v $(pwd):/src yalibc-dev scons

Run with

docker run --rm -it -v $(pwd):/src yalibc-dev ./main

## Aliases

alias scons="docker run --rm -it -v $(pwd):/src yalibc-dev scons"
alias run="docker run --rm -it -v $(pwd):/src yalibc-dev ./main"
