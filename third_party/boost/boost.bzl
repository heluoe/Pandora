load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@//third_party:opencode_remotes.bzl", "BOOST_ARCHIVE_CC")
load("@//bazel/rules:opencode.bzl", "opencode_archive")

def create_alias_rules(modules):
    """Helper method to reduce code duplication for alias creation

    Args:
      modules: the list of modules for which to create aliases
    """

    for module in modules:
        native.alias(
            name = module,
            actual = "@boost_171//:{}".format(module),
            visibility = [
                "//examples:__subpackages__",
                "//visibility:public",
            ],
        )

def boost_deps():
    maybe(
        opencode_archive,
        name = "boost_171",
        build_file = "//third_party/boost:boost_171.BUILD",
        repo = BOOST_ARCHIVE_CC,
        path = "boost_1_71_0.tar.gz",
        strip_prefix = "boost_1_71_0/",
        sha256 = "96b34f7468f26a141f6020efb813f1a2f3dfb9797ecf76a7d7cbd843cc95f5bd",
    )
