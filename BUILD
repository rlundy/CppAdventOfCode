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
    srcs = glob([
        "src/*.cpp"
    ]),
    hdrs = glob([
        "include/*.hpp"
    ]),
    includes = [
        "include",
    ],
)

cc_test(
    name = "tests_runner",
    srcs = glob([
        "tests/*.cpp"
    ]),
    deps = [
        ":adventOfCodeLib",
        ":catch2_lib",
    ],
    includes = [
        "tests"
    ],
)

cc_binary(
    name = "adventOfCodeProgram",
    srcs = [
        "src/main.cpp"
    ],
    deps = [
        ":adventOfCodeLib"
    ],
)
