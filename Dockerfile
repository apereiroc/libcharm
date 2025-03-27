FROM ubuntu:22.04

# install required dev tools
RUN apt update && apt install -y \
    clang \
    gcc \
    # for dev, ausyscall --dump
    auditd \
    scons

# copy the source code
COPY . /src

# change working directory
WORKDIR /src
