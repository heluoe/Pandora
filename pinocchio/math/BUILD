load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "math",
    hdrs = glob([
        "*.hpp",
    ]),
    visibility = [
        "//pinocchio:__subpackages__",
    ],
    deps = [
        "//third_party:eigen",
        "@boost_171//:math",
    ],
)