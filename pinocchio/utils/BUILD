load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "utils",
    hdrs = glob([
        "*.hpp",
    ]),
    visibility = [
        "//examples:__subpackages__",
        "//pinocchio:__subpackages__",        
    ],
    deps = [
        "//pinocchio:pinocchio",
    ],
)