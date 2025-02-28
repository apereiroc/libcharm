FROM --platform=linux/amd64 ubuntu:22.04

# install required dev tools
RUN apt update && apt install -y \
    # build-base \
    clang \
    make \
    # nasm \
    # libc-dev \
    gcc \
    g++ \
    # linux-headers \
    # x86_64-linux-gnu-gcc \
    # binutils \
    scons

# copy the source code
COPY . /src

# change working directory
WORKDIR /src
