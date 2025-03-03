import os
import glob
import sys


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
    # Disabled Warnings
    "-Wno-unknown-pragmas",  # Some compilers complain about our use of #pragma mark
    "-Wno-padded",
    # Desired Warnings
    "-Wfloat-equal",
    "-Wconversion",
    "-Wundef",
    "-Wredundant-decls",
    "-Wshadow",
    "-Wstrict-overflow=2",
    "-Wwrite-strings",
    "-Wpointer-arith",
    "-Wcast-qual",
    "-Wformat=2",
    "-Wmissing-include-dirs",
    "-Wcast-align",
    "-Wswitch-enum",
    "-Wsign-conversion",
    "-Wdisabled-optimization",
    "-Winvalid-pch",
    "-Wmissing-declarations",
    "-Wdouble-promotion",
    "-Wshadow",
    "-Wnull-dereference",
    "-Wnull-dereference",
    "-Wcast-align",
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
    "-Wno-global-constructors",  # causes warnings if you use static values
    "-Wno-exit-time-destructors",  # causes warnings if you use static values
]

"""
    Compilation flags
"""

common_compilation_flags = []

gcc_compilation_flags = common_compilation_flags + []
clang_compilation_flags = common_compilation_flags + []

"""
    Optimization flags
"""
debug_flags = [
    "-O0",
    "-g",
]


release_flags = [
    "-O2",
    "-g",
    # "-DNDEBUG",  # eliminates asserts?
]

"""
    Linkflags
"""

common_linkflags = ["-nostdlib", "-ffreestanding"]

gcc_linkflags = common_linkflags + []
clang_linkflags = common_linkflags + []

"""
    Include dirs
"""

include_dirs = [
    # here
    "#"
]

"""
    Libraries
"""


"""
    Construction environments
"""

env = Environment(ENV=os.environ, CCPATH=include_dirs)
env.Tool("compilation_db")
env.CompilationDatabase()

gcc_opt_flags = gcc_warning_flags + gcc_compilation_flags + release_flags
gcc_dbg_flags = gcc_warning_flags + gcc_compilation_flags + debug_flags
clang_opt_flags = clang_warning_flags + clang_compilation_flags + release_flags
clang_dbg_flags = clang_warning_flags + clang_compilation_flags + debug_flags

env_gcc_opt = env.Clone(
    CC="x86_64-linux-gnu-gcc", CCFLAGS=gcc_opt_flags, LINKFLAGS=gcc_linkflags
)
env_gcc_dbg = env.Clone(
    CC="x86_64-linux-gnu-gcc", CCFLAGS=gcc_dbg_flags, LINKFLAGS=gcc_linkflags
)
env_clang_opt = env.Clone(
    CC="clang", CCFLAGS=clang_opt_flags, LINKFLAGS=clang_linkflags
)
env_clang_dbg = env.Clone(
    CC="clang", CCFLAGS=clang_dbg_flags, LINKFLAGS=clang_linkflags
)


"""
    Build the binary/binaries
"""


# helper function
def _get_objects_with_env(env_label, src_files):
    list_of_objs = []
    for src_file in src_files:
        name, _ = os.path.splitext(src_file)
        obj = f"{name}-{env_label}.o"
        list_of_objs.append(obj)
    return list_of_objs


# actual builder
def build_program(env, env_label, src_files):
    object_files = _get_objects_with_env(env_label=env_label, src_files=source_files)
    objs = [env.Object(obj, src) for obj, src in zip(object_files, src_files)]

    # start_asm = env.Object(f"start-{env_label}.o", "start.s")
    # prog = env.Program(f"main-{env_label}", start_asm + objs)
    prog = env.Program(f"main-{env_label}", objs)
    return prog


source_files = glob.glob("*.c") + glob.glob("*.S")

# GCC debug
prog_gcc_dbg = build_program(
    env=env_gcc_dbg, env_label="gcc-dbg", src_files=source_files
)

# GCC release
prog_gcc_opt = build_program(
    env=env_gcc_opt, env_label="gcc-opt", src_files=source_files
)

# Clang debug
prog_clang_dbg = build_program(
    env=env_clang_dbg, env_label="clang-dbg", src_files=source_files
)

# Clang release
prog_clang_opt = build_program(
    env=env_clang_opt, env_label="clang-opt", src_files=source_files
)

if sys.platform == "darwin":
    Default(
        [
            prog_clang_dbg,
        ]
    )
else:
    Default(
        [
            prog_gcc_dbg,
        ]
    )
