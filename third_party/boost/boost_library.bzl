include_pattern = "boost/%s/"

hdrs_patterns = [
    "boost/%s.h",
    "boost/%s_fwd.h",
    "boost/%s.hpp",
    "boost/%s_fwd.hpp",
    "boost/%s/**/*.hpp",
    "boost/%s/**/*.ipp",
    "boost/%s/**/*.h",
    "libs/%s/src/*.ipp",
]

srcs_patterns = [
    "libs/%s/src/*.cpp",
    "libs/%s/src/*.hpp",
]

def _srcs_list(library_name, exclude):
    return native.glob(
        [p % (library_name,) for p in srcs_patterns],
        exclude = exclude,
    )

def _includes_list(library_name):
    return [".", include_pattern % library_name]

def _hdr_list(library_name):
    return native.glob([p % (library_name,) for p in hdrs_patterns])

def boost_library(
        name,
        defines = None,
        includes = None,
        hdrs = None,
        srcs = None,
        deps = None,
        copts = None,
        exclude_src = [],
        linkopts = None,
        visibility = None):
    """Declare a boost boost library

    Args:
      name:name
      defines:defines
      includes:includes
      hdrs:hdrs
      srcs:srcs
      deps:deps
      copts:copts
      exclude_src:exclude_src
      linkopts:linkopts
      visibility:visibility
    Returns:
      A native cc_library
    """

    if defines == None:
        defines = []

    if includes == None:
        includes = []

    if hdrs == None:
        hdrs = []

    if srcs == None:
        srcs = []

    if deps == None:
        deps = []

    if copts == None:
        copts = []

    if linkopts == None:
        linkopts = []

    return native.cc_library(
        name = name,
        visibility = visibility,
        defines = defines + ["BOOST_AUTO_LINK_NOMANGLE"],
        includes = _includes_list(name) + includes,
        hdrs = _hdr_list(name) + hdrs,
        srcs = _srcs_list(name, exclude_src) + srcs,
        deps = deps,
        copts = copts,
        features = ["third_party_warnings"],
        linkopts = linkopts,
        licenses = ["notice"],
    )
