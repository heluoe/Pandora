load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])
 
EIGEN_FILES = [
    "eigen/Eigen/**",
    "eigen/unsupported/**",
]

EIGEN_EXCLUDE_FILES = [
    "eigen/Eigen/*Support",
]

# Files known to be under MPL2 license.
EIGEN_MPL2_HEADER_FILES = glob(
    EIGEN_FILES,
    exclude = EIGEN_EXCLUDE_FILES + [
        # Guarantees any file missed by excludes above will not compile.
        "eigen/Eigen/src/Core/util/NonMPL2.h",
        "eigen/Eigen/**/CMakeLists.txt",
    ],
)

cc_library(
    name = "eigen",
    hdrs = EIGEN_MPL2_HEADER_FILES,
    defines = [
        "EIGEN_MPL2_ONLY",
    ],
    includes = ["eighen/."],
)
