import os
import glob
import platform
from SCons.Script import Environment, AddOption, GetOption


# check whether system is Linux/Darwin
system_name = platform.system().lower()

if system_name not in ["linux", "darwin"]:
    print(f"System name `{system_name}` is not supported")
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
    default="gcc" if system_name == "linux" else "clang",
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
    "-Wstack-protector",
    "-Wno-pointer-to-int-cast",
    "-Werror=implicit-function-declaration",
    "-Werror=implicit-int",
    "-Werror=pointer-sign",
    "-Werror=pointer-arith",
    "-Werror=incompatible-pointer-types",
    "-Waddress",
    "-Warray-bounds",
    "-Wchar-subscripts",
    "-Wduplicate-decl-specifier",
    "-Winit-self",
    "-Wreturn-type",
    "-Wsequence-point",
    "-Wstrict-aliasing",
    "-Wunused-function",
    "-Wunused-label",
    "-Wunused-variable",
    "-Werror=int-conversion",
]

gcc_warning_flags = common_warning_flags + [
    "-Wlogical-op",
    "-Wtrampolines",
    "-Wvector-operation-performance",
    "-Wformat-truncation",
    "-Wshift-overflow=2",
    "-Wduplicated-cond",
    "-Wcast-align=strict",
    "-Werror=discarded-qualifiers",
    "-Werror=discarded-array-qualifiers",
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
    # for now avoid stack protection against overflow
    # TODO: eventually implement __stack_chk_fail, ___stack_chk_guard
    "-fno-stack-protector",
    "-nostdlib",
    "-ffreestanding",
    # "-nostartfiles",
    "-nostdinc",
]

# gcc-only compilation flags go here
gcc_compilation_flags = common_compilation_flags + []

# clang-only compilation flags go here
clang_compilation_flags = common_compilation_flags + [
    "-nobuiltininc",
    "-nostdlibinc",
]

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
    "-nostartfiles",
    "-nostdinc",
    "-nodefaultlibs",
    "-Wl,-e,_start",
]

# gcc-only linkflags go here
gcc_linkflags = common_linkflags + []

# clang-only linkflags go here
clang_linkflags = common_linkflags + [
    "-nostdlibinc",
    "-nobuiltininc",
]

"""
    Include dirs
"""

include_dirs = [
    "#",
    "#include",
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
output_dir = f"target/{system_name.lower()}-{arch_name}-{compiler}-{build_type}"
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


# get source files
source_files = (
    glob.glob(
        "src/**/*.c",
        recursive=True,
    )
    + glob.glob(
        "src/**/*.S",
        recursive=True,
    )
    + [f"crt/{system_name}/{arch_name}/crt0.S"]
)

# create object files at output directory
obj_files = []
for src_file in source_files:
    src_name, src_ext = os.path.splitext(os.path.basename(src_file))
    obj_name = os.path.join(output_dir, src_name + ".o")
    bin_name = os.path.join(output_dir, src_name)

    env.Object(obj_name, src_file)
    obj_files.append(obj_name)

# create the library at output directory from object files
env.Library(os.path.join(output_dir, "charm"), obj_files)

# build main at output directory
env.Object(os.path.join(output_dir, "main.o"), "main.c")

# link main against the library
env.Program(os.path.join(output_dir, "main.o"), LIBS=["charm"], LIBPATH=output_dir)


# add a 'run' target that runs all test binaries
def run_main(target, source, env):
    bin = os.path.join(output_dir, "main")
    ret = os.system(bin)
    if ret != 0:
        actual_ret = os.waitstatus_to_exitcode(ret)
        print(f"error: `main` exit with error code {actual_ret}")
        return 1
    return ret


# create a main target
# can be called by running `scons run`
main_target = env.Alias("run", os.path.join(output_dir, "main"), run_main)

# always build this target
# otherwise it will say that it is already built
env.AlwaysBuild(main_target)

"""
    Build tests
"""
test_src_dir = "tests"
test_lib_dir = os.path.join(test_src_dir, "lib")
test_lib_src_dir = os.path.join(test_lib_dir, "src")
test_lib_inc_dir = os.path.join(test_lib_dir, "include")
test_output_dir = os.path.join(output_dir, "tests")
test_lib_name = "test_libcharm"


# build object files of testing library
env.AppendUnique(CPPPATH=[test_lib_inc_dir])

env.Object(
    os.path.join(test_output_dir, "testing_lib.o"),
    os.path.join(test_lib_src_dir, "testing_lib.c"),
)

# create a testing library from the objects
# and also link syscall (needed for write and exit in the testing framework)
env.Library(
    os.path.join(test_output_dir, test_lib_name),
    [
        os.path.join(test_output_dir, "testing_lib.o"),
        os.path.join(output_dir, "syscall.o"),
        os.path.join(output_dir, "syscall_wrapper.o"),
    ],
)


# get test source files
# exclude the testing library
test_source_files = [f for f in glob.glob(f"{test_src_dir}/*.c")]

# for each testing source file, create an executable at test output directory
test_binary_files = []
for src_file in test_source_files:
    src_name, _ = os.path.splitext(os.path.basename(src_file))
    obj_name = os.path.join(test_output_dir, src_name + ".o")
    bin_name = os.path.join(test_output_dir, src_name)

    env.Object(obj_name, src_file)

    env.Program(
        bin_name,
        obj_name,
        LIBS=["charm", test_lib_name],
        LIBPATH=[output_dir, test_output_dir],
    )
    test_binary_files.append(bin_name)


# add a 'test' target that runs all test binaries
def run_tests(target, source, env):
    print("\nRunning tests...\n")
    failures = 0
    for test_bin in test_binary_files:
        result = os.system(test_bin)
        if result != 0:
            failures += 1

    if failures > 0:
        print(f"\n{failures} test(s) failed.")
        return 1

    print("\nAll tests passed!")
    return 0


# create a test target
# can be called by running `scons test`
test_target = env.Alias("test", test_binary_files, run_tests)

# always build this target
# otherwise it will say that it is already built
env.AlwaysBuild(test_target)
