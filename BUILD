cc_library(
    name = "catch2_lib",
    srcs = [
        "tests/catch_amalgamated.cpp"
    ],
    hdrs = [
        "tests/catch_amalgamated.hpp"
    ],
    copts = [],
)

cc_library(
    name = "adventOfCodeLib",
    srcs = [
        "src/Year2015.cpp",
        "src/Year2016.cpp",
        "src/Util.cpp",
    ],
    hdrs = [
        "include/Year2015.hpp",
        "include/Year2016.hpp",
        "include/Util.hpp",
    ],
    includes = [
        "include",
    ],
)

cc_test(
    name = "tests_runner",
    srcs = [
        "tests/tests_main.cpp",
        "tests/Year2015Tests.cpp",
        "tests/Year2016Tests.cpp",
        "tests/UtilTests.cpp",
    ],
    deps = [
        ":adventOfCodeLib",
        ":catch2_lib",
    ],
    includes = ["tests"],
)

cc_binary(
    name = "adventOfCodeProgram",
    srcs = ["src/main.cpp"],
    deps = [":adventOfCodeLib"],
)
