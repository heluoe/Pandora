load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "interpolation-SE3",
    srcs = ["interpolation-SE3.cpp"],
    deps = [
        "//pinocchio/multibody/liegroup:liegroup",
        "@eigen",
        "@boost_171//:algorithm",
    ],
)
