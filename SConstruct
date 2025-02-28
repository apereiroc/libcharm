import os


"""
    Warning flags
"""
# TODO: to be checked in a docker file...
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
    "-Wno-c++98-compat",
    "-Wno-c++98-compat-pedantic",
    "-Wno-padded",
    "-Wno-exit-time-destructors",  # causes warnings if you use static values
    "-Wno-global-constructors",  # causes warnings if you use static values
    "-Wno-covered-switch-default",
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

# TODO: to be checked in a docker file...
gcc_warning_flags = common_warning_flags + [
    "-Wlogical-op",
    "-Wtrampolines",
    "-Wvector-operation-performance",
    "-Wformat-truncation",
    "-Wshift-overflow=2",
    "-Wduplicated-cond",
    "-Wcast-align=strict",
]

clang_warning_flags = common_warning_flags + []

"""
    Debug flags
"""
debug_flags = [
    "-O0",
    "-g",
]

"""
    Release_flags
"""
release_flags = [
    "-O2",
    "-g",
    "-DNDEBUG",  # eliminates asserts?
]

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

env_gcc_opt = env.Clone(CC="gcc", CCFLAGS=gcc_warning_flags + release_flags)
env_gcc_dbg = env.Clone(CC="gcc", CCFLAGS=gcc_warning_flags + debug_flags)
env_clang_opt = env.Clone(CC="clang", CCFLAGS=clang_warning_flags + release_flags)
env_clang_dbg = env.Clone(CC="clang", CCFLAGS=clang_warning_flags + debug_flags)

# Export environment
# Export("env")
"""
    Build the binary/binaries
"""

sources = Glob("*.c")

# prog_gcc_opt = env_gcc_opt.Program(target="main-gcc-opt", source=sources)
# prog_gcc_dbg = env_gcc_opt.Program(target="main-gcc-dbg", source=sources)
# prog_clang_opt = env_clang_opt.Program(target="main-clang-opt", source=sources)
prog_clang_dbg = env_clang_opt.Program(target="main", source=sources)

Default(prog_clang_dbg)
