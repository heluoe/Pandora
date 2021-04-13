load("@//third_party/boost:boost.bzl", "boost_deps")
load("@//third_party/eigen:eigen.bzl", "eigen")
  

def third_party_deps():
    """Load 3rd party dependencies"""
    boost_deps()
    eigen()
   