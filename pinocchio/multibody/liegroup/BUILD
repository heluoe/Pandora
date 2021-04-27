load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "liegroup",
    hdrs = glob([
        "*.hpp",
        "*.hxx",
    ]),
    visibility = [
        "//examples:__subpackages__",
        "//tests:__subpackages__",
        "//pinocchio:__subpackages__",        
    ],
    deps = [
        "//pinocchio/container:container",
        "//pinocchio/math:math",
        "//pinocchio:pinocchio",
        "//pinocchio/spatial:spatial",
        "//pinocchio/utils:utils",
        "@boost_171//:integer",
        "@boost_171//:lexical_cast",
        "//third_party:eigen"
    ],
)