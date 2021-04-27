load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "spatial",
    hdrs = glob([
        "*.hpp",
        "*.hxx",
    ]),
    visibility = [
        "//pinocchio:__subpackages__",
    ],
    deps = [
        "//third_party:eigen",
    ],
)