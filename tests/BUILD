
cc_test(
    name = "unit_test_se",
    srcs = glob([
        "interpolation_se_unit_tests.cpp",
    ]),
    features = [
        "treat_warnings_as_errors",
    ],
    tags = [
        "unit",
    ],
    deps = [
        "//pinocchio/multibody/liegroup:liegroup",
        "//third_party:eigen",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "unit_test_qr",
    srcs = glob([
        "colpivhouseholderqr_eigen_tests.cpp",
    ]),
    features = [
        "treat_warnings_as_errors",
    ],
    tags = [
        "unit",
    ],
    deps = [
        "//third_party:eigen",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)