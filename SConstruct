import os
import glob
import platform
from SCons.Script import ARGUMENTS, Environment
from SCons.Script import Environment, AddOption, GetOption, Default


# check whether system is Linux/Darwin
system_name = platform.system()

if system_name not in ["Linux", "Darwin"]:
    print(f"System name `{system_name}` is not supported")
    print("Please use `x86_64`, `arm64`, or `aarch64`")
    exit(1)

# check whether arch is x86_64, arm64, aarch64
arch_name = platform.machine()

if arch_name not in ["x86_64", "arm64", "aarch64"]:
    print(f"Architecture `{arch_name}` is not supported")
    print("Please use `x86_64`, `arm64`, or `aarch64`")
    exit(1)

"""
    Define command line options
"""
AddOption(
    "--compiler",
    dest="compiler",
    type="string",
    nargs=1,
    action="store",
    default="gcc" if platform.system() == "Linux" else "clang",
    help="Choose the compiler: `gcc` or `clang` (default: auto-detected)",
)

AddOption(
    "--build",
    dest="build",
    type="string",
    nargs=1,
    action="store",
    default="debug",
    help="Build type: `debug` or `release` (default: debug)",
)

# get user options
compiler = GetOption("compiler")
build_type = GetOption("build")


"""
    Warning flags
"""

common_warning_flags = [
    "-Wall",
    "-Wextra",
    "-pedantic",
    "-Wshadow",
    "-Wconversion",
    "-Wuninitialized",
    "-Wnull-dereference",
    "-Wdouble-promotion",
    "-Wstrict-overflow",
    "-Wformat=2",
    "-Wno-unknown-pragmas",
    "-Wno-padded",
    "-Wfloat-equal",
    "-Wundef",
    "-Wredundant-decls",
    "-Wwrite-strings",
    "-Wpointer-arith",
    "-Wcast-qual",
    "-Wmissing-include-dirs",
    "-Wcast-align",
    "-Wswitch-enum",
    "-Wsign-conversion",
    "-Wdisabled-optimization",
    "-Winvalid-pch",
    "-Wmissing-declarations",
    "-Wshift-overflow",
]

gcc_warning_flags = common_warning_flags + [
    "-Wlogical-op",
    "-Wtrampolines",
    "-Wvector-operation-performance",
    "-Wformat-truncation",
    "-Wshift-overflow=2",
    "-Wduplicated-cond",
    "-Wcast-align=strict",
]

clang_warning_flags = common_warning_flags + [
    "-Wno-c++98-compat",
    "-Wno-c++98-compat-pedantic",
    "-Wno-covered-switch-default",
    "-Wno-global-constructors",
    "-Wno-exit-time-destructors",
]

"""
    Compilation flags
"""

# your compilation flags go here
common_compilation_flags = [
    "-std=c99",
]

# gcc-only compilation flags go here
gcc_compilation_flags = common_compilation_flags + []

# clang-only compilation flags go here
clang_compilation_flags = common_compilation_flags + []

"""
    Optimisation flags for debug/release
"""

debug_flags = [
    "-O0",
    "-g",
]

release_flags = [
    "-O2",
]

"""
    Linkflags
"""

# your linkflags go here
common_linkflags = [
    "-nostdlib",
    "-ffreestanding",
]

# gcc-only linkflags go here
gcc_linkflags = common_linkflags + []

# clang-only linkflags go here
clang_linkflags = common_linkflags + []

"""
    Include dirs
"""

include_dirs = [
    "#",
]

"""
    Libraries
"""
# unused in this project


"""
    Build
"""
# choose appropriate flags based on compiler
if compiler == "gcc":
    compilation_flags = gcc_warning_flags + gcc_compilation_flags
    link_flags = gcc_linkflags
    cc_binary = "gcc"
elif compiler == "clang":
    compilation_flags = clang_warning_flags + clang_compilation_flags
    link_flags = clang_linkflags
    cc_binary = "clang"
else:
    print(f"Unsupported compiler `{compiler}`. Use `gcc` or `clang`.")
    exit(1)

# choose appropriate optimisation flags
if build_type == "debug":
    compilation_flags += debug_flags
elif build_type == "release":
    compilation_flags += release_flags
else:
    print(f"Unknown build type `{build_type}`. Use `debug` or `release`.")
    exit(1)

# determine output directory
output_dir = f"target/{compiler}-{build_type}-{arch_name}"
os.makedirs(output_dir, exist_ok=True)

# create the build environment
env = Environment(
    ENV=os.environ,
    CC=cc_binary,
    CCFLAGS=compilation_flags,
    LINKFLAGS=link_flags,
    CPPPATH=include_dirs,
)
env.Tool("compilation_db")
env.CompilationDatabase()


# build the program
def build_program(env, src_files):
    objs = [
        env.Object(os.path.join(output_dir, os.path.splitext(src)[0] + ".o"), src)
        for src in src_files
    ]
    prog = env.Program(os.path.join(output_dir, "main"), objs)
    return prog


source_files = glob.glob("*.c") + glob.glob("*.S")
prog = build_program(env, source_files)

Default(prog)
