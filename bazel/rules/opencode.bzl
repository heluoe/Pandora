"""Rules and macros to facilitate usage of binary artifacts hosted on artifactory"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def _get_url(repo, path):
    """Join repo and path with / to obtain the url"""
    return repo.rstrip("/") + "/" + path


def opencode_archive(name, repo, path, **kwargs):
    http_archive(
        name = name,
        url = _get_url(repo, path),
        **kwargs
    )