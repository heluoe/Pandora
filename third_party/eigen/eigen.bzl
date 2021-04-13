load("@//third_party:opencode_remotes.bzl", "EIGEN3_ARCHIVE_CC")
load("@//bazel/rules:opencode.bzl", "opencode_archive")

# TYPE: upstream
# LICENSE: MPL-2
# CONTACT:
def eigen():
    if "eigen" not in native.existing_rules():
        opencode_archive(
            name = "eigen",
            repo = EIGEN3_ARCHIVE_CC,
            path = "eigen-3.3.5.tar.bz2",
            sha256 = "0208f8d3d5f3b9fd1a022c5f47d6ebbd6f11c4ed6e756764871bf4ffb1e117a1",
            build_file = "//third_party/eigen:eigen.BUILD",
            strip_prefix = "eigen-3.3.5",
        )
