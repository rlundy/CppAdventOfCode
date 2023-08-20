# This is a Bazel BUILD file. It defines how Bazel should build and test your C++ project.

# Define a C++ library target. This compiles the Calculator logic into a library.
cc_library(
    # The name of this build target. Other rules can reference this with ':calculator_lib'.
    name = "calculator_lib",
    
    # The source files to compile for this library.
    srcs = [
        "src/Calculator.cpp",
        "src/Year2015.cpp"
    ],
    
    # The header files that are part of this library.
    hdrs = [
        "include/calculator.hpp",
        "include/Year2015.hpp"
    ],
    
    # Directories that should be added to the include path when this library is used.
    includes = ["include"],
    
    # Compiler options for this target. Here, we're specifying C++17 standard.
    copts = ["/std:c++17"],
)

# Define a C++ test target. This compiles and runs tests for the calculator.
cc_test(
    # The name of the test runner target.
    name = "tests_runner",
    
    # The source files to compile for this test target.
    srcs = [
        "tests/calculator_tests.cpp",
        "tests/tests_main.cpp",
        "tests/catch_amalgamated.cpp",
        "tests/Year2015Tests.cpp"
    ],
    
    # Dependencies for this target. We depend on the 'calculator_lib' library defined above.
    deps = [":calculator_lib"],
    
    # Compiler options for this test target.
    copts = ["/std:c++17"],
    
    # Directories that should be added to the include path when these tests are compiled.
    includes = ["tests"],
)

# Define a C++ binary target. This compiles the main calculator program into an executable.
cc_binary(
    # The name of the binary target.
    name = "calculator_program",
    
    # The source file that contains the 'main' function for the program.
    srcs = ["src/main.cpp"],
    
    # Dependencies for this target. We depend on the 'calculator_lib' library defined above.
    deps = [":calculator_lib"],
    
    # Compiler options for this binary target.
    copts = ["/std:c++17"],
)
