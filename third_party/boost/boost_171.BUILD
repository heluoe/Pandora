load("@//third_party/boost:boost_library.bzl", "boost_library")

 
config_setting(
    name = "linux_x86_64",
    constraint_values = [
        "@bazel_tools//platforms:linux",
        "@bazel_tools//platforms:x86_64",
    ],
)

config_setting(
    name = "linux",
    constraint_values = [
        "@bazel_tools//platforms:linux",
    ],
)

config_setting(
    name = "windows_x86_64",
    constraint_values = [
        "@bazel_tools//platforms:windows",
        "@bazel_tools//platforms:x86_64",
    ],
)

BOOST_CTX_ASM_SOURCES = select({
    ":linux_x86_64": [
        "libs/context/src/asm/jump_x86_64_sysv_elf_gas.S",
        "libs/context/src/asm/make_x86_64_sysv_elf_gas.S",
        "libs/context/src/asm/ontop_x86_64_sysv_elf_gas.S",
    ],
    ":windows_x86_64": [
        "libs/context/src/asm/make_x86_64_ms_pe_masm.asm",
        "libs/context/src/asm/jump_x86_64_ms_pe_masm.asm",
        "libs/context/src/asm/ontop_x86_64_ms_pe_masm.asm",
    ],
})

boost_library(
    name = "context",
    srcs = BOOST_CTX_ASM_SOURCES + select({
        ":linux_x86_64": [
            "libs/context/src/posix/stack_traits.cpp",
        ],
        ":windows_x86_64": [
            "libs/context/src/windows/stack_traits.cpp",
        ],
    }),
    exclude_src = [
        "libs/context/src/untested.cpp",
        "libs/context/src/continuation.cpp",
        "libs/context/src/fiber.cpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":config",
        ":cstdint",
        ":detail",
        ":intrusive_ptr",
    ],
)

BOOST_FIBER_NUMA_SRCS = select({
    ":linux_x86_64": [
        "libs/fiber/src/numa/linux/pin_thread.cpp",
        "libs/fiber/src/numa/linux/topology.cpp",
    ],
    ":windows_x86_64": [
        "libs/fiber/src/numa/windows/pin_thread.cpp",
        "libs/fiber/src/numa/windows/topology.cpp",
    ],
})

boost_library(
    name = "fiber",
    srcs = BOOST_FIBER_NUMA_SRCS + glob(["libs/fiber/src/algo/**/*.cpp"]),
    copts = select({
        ":windows_x86_64": [
            "/D_WIN32_WINNT=0x0601",
        ],
        "//conditions:default": [],
    }),
    exclude_src = ["libs/fiber/src/numa/**/*.cpp"],
    linkopts = select({
        ":linux_x86_64": [
            "-lpthread",
        ],
        "//conditions:default": [],
    }),
    visibility = ["//visibility:public"],
    deps = [
        ":algorithm",
        ":context",
        ":filesystem",
        ":format",
        ":intrusive",
        ":intrusive_ptr",
        ":pool",
    ],
)

boost_library(
    name = "pool",
    visibility = ["//visibility:public"],
    deps = [
        ":integer",
        ":assert",
        ":config",
        ":detail",
        ":limits",
        ":throw_exception",
        ":type_traits",
    ],
)

boost_library(
    name = "algorithm",
    visibility = ["//visibility:public"],
    deps = [
        ":function",
        ":iterator",
        ":range",
    ],
)

boost_library(
    name = "align",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "any",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":mpl",
        ":static_assert",
        ":throw_exception",
        ":type_index",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "assign",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":detail",
        ":mpl",
        ":preprocessor",
        ":ptr_container",
        ":range",
        ":static_assert",
        ":type_traits",
    ],
)

boost_library(
    name = "atomic",
    hdrs = [
        "boost/memory_order.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":config",
        ":cstdint",
        ":type_traits",
    ],
)

boost_library(
    name = "archive",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":cstdint",
        ":integer",
        ":io",
        ":iterator",
        ":mpl",
        ":noncopyable",
        ":smart_ptr",
        ":spirit",
    ],
)

boost_library(
    name = "array",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":config",
        ":core",
        ":functional",
        ":swap",
        ":throw_exception",
    ],
)

boost_library(
    name = "asio",
    linkopts = ["-lpthread"],
    defines = ["BOOST_ASIO_DISABLE_STD_EXPERIMENTAL_STRING_VIEW"],
    visibility = ["//visibility:public"],
    deps = [
        ":bind",
        ":date_time",
        ":regex",
    ],
)

boost_library(
    name = "assert",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "beast",
    visibility = ["//visibility:public"],
    deps = [
        ":asio",
        ":config",
        ":core",
        ":detail",
        ":endian",
        ":logic",
        ":mp11",
        ":smart_ptr",
        ":static_assert",
        ":system",
        ":throw_exception",
        ":utility",
    ],
)

boost_library(
    name = "bimap",
    visibility = ["//visibility:public"],
    deps = [
        ":concept_check",
        ":multi_index",
        ":serialization",
    ],
)

boost_library(
    name = "bind",
    visibility = ["//visibility:public"],
    deps = [
        ":get_pointer",
        ":is_placeholder",
        ":mem_fn",
        ":ref",
        ":type",
        ":visit_each",
    ],
)

boost_library(
    name = "callable_traits",
    visibility = ["//visibility:public"],
    deps = [
    ],
)

boost_library(
    name = "call_traits",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "cerrno",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "checked_delete",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "chrono",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":mpl",
        ":operators",
        ":predef",
        ":ratio",
        ":system",
        ":throw_exception",
        ":type_traits",
    ],
)

boost_library(
    name = "circular_buffer",
    visibility = ["//visibility:public"],
    deps = [
        ":call_traits",
        ":concept_check",
        ":config",
        ":container",
        ":detail",
        ":iterator",
        ":limits",
        ":move",
        ":static_assert",
        ":throw_exception",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "compute",
    linkopts = [
        "-lOpenCL",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":algorithm",
        ":chrono",
        ":config",
        ":throw_exception",
    ],
)

boost_library(
    name = "concept_archetype",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":iterator",
        ":mpl",
    ],
)

boost_library(
    name = "concept_check",
    visibility = ["//visibility:public"],
    deps = [
        ":concept",
        ":concept_archetype",
    ],
)

boost_library(
    name = "config",
    visibility = ["//visibility:public"],
    deps = [
        ":version",
    ],
)

boost_library(
    name = "concept",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "container",
    srcs = [
        "libs/container/src/dlmalloc_ext_2_8_6.c",
    ],
    hdrs = [
        "libs/container/src/dlmalloc_2_8_6.c",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":core",
        ":intrusive",
        ":move",
    ],
)

boost_library(
    name = "conversion",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "core",
    srcs = [
        "boost/checked_delete.hpp",
    ],
    visibility = ["//visibility:public"],
)

BOOST_CORO_SRCS = select({
    ":linux_x86_64": [
        "libs/coroutine/src/posix/stack_traits.cpp",
    ],
    ":windows_x86_64": [
        "libs/coroutine/src/windows/stack_traits.cpp",
    ],
})

boost_library(
    name = "coroutine",
    srcs = BOOST_CORO_SRCS + [
        "libs/coroutine/src/detail/coroutine_context.cpp",
    ],
    deps = [
        ":config",
        ":context",
        ":move",
        ":range",
        ":system",
        ":thread",
    ],
)

boost_library(
    name = "cstdint",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "current_function",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "date_time",
    srcs = glob([
        "libs/date_time/src/gregorian/*.cpp",
        "libs/date_time/src/gregorian/*.hpp",
    ]),
    visibility = ["//visibility:public"],
    deps = [
        ":algorithm",
        ":io",
        ":lexical_cast",
        ":mpl",
        ":operators",
        ":smart_ptr",
        ":static_assert",
        ":tokenizer",
        ":type_traits",
    ],
)

boost_library(
    name = "detail",
    hdrs = [
        "boost/blank.hpp",
        "boost/blank_fwd.hpp",
        "boost/cstdlib.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":call_traits",
        ":limits",
    ],
)

boost_library(
    name = "dynamic_bitset",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":core",
        ":detail",
        ":integer",
        ":move",
        ":throw_exception",
        ":utility",
    ],
)

boost_library(
    name = "enable_shared_from_this",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "endian",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":core",
        ":cstdint",
        ":detail",
        ":predef",
        ":type_traits",
    ],
)

boost_library(
    name = "exception",
    hdrs = [
        "boost/exception_ptr.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":detail",
    ],
)

boost_library(
    name = "exception_ptr",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
    ],
)

boost_library(
    name = "filesystem",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":functional",
        ":io",
        ":iterator",
        ":range",
        ":smart_ptr",
        ":system",
        ":type_traits",
    ],
)

boost_library(
    name = "foreach",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":detail",
        ":iterator",
        ":mpl",
        ":noncopyable",
        ":range",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "format",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":config",
        ":detail",
        ":limits",
        ":optional",
        ":smart_ptr",
        ":throw_exception",
        ":timer",
        ":utility",
    ],
)

boost_library(
    name = "function",
    hdrs = [
        "boost/function_equal.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":bind",
        ":integer",
        ":type_index",
    ],
)

boost_library(
    name = "function_types",
)

boost_library(
    name = "functional",
    visibility = ["//visibility:public"],
    deps = [
        ":container_hash",
        ":detail",
        ":integer",
    ],
)

boost_library(
    name = "fusion",
    visibility = ["//visibility:public"],
    deps = [
        ":call_traits",
        ":config",
        ":core",
        ":detail",
        ":function_types",
        ":functional",
        ":get_pointer",
        ":mpl",
        ":preprocessor",
        ":ref",
        ":static_assert",
        ":tuple",
        ":type_traits",
        ":typeof",
        ":utility",
    ],
)

boost_library(
    name = "geometry",
    visibility = ["//visibility:public"],
    deps = [
        ":algorithm",
        ":call_traits",
        ":config",
        ":function_types",
        ":lexical_cast",
        ":math",
        ":mpl",
        ":numeric",
        ":qvm",
        ":range",
        ":rational",
        ":tokenizer",
        ":variant",
    ],
)

boost_library(
    name = "property_tree",
    visibility = ["//visibility:public"],
    deps = [
        ":any",
        ":bind",
        ":format",
        ":multi_index",
        ":optional",
        ":range",
        ":ref",
        ":throw_exception",
        ":utility",
    ],
)

boost_library(
    name = "get_pointer",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "heap",
    visibility = ["//visibility:public"],
    deps = [
        ":parameter",
    ],
)

boost_library(
    name = "icl",
    visibility = ["//visibility:public"],
    deps = [
        ":concept_check",
    ],
)

boost_library(
    name = "is_placeholder",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "integer",
    hdrs = [
        "boost/cstdint.hpp",
        "boost/integer_traits.hpp",
        "boost/pending/integer_log2.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":static_assert",
    ],
)

boost_library(
    name = "interprocess",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":checked_delete",
        ":config",
        ":container",
        ":core",
        ":date_time",
        ":detail",
        ":integer",
        ":intrusive",
        ":limits",
        ":move",
        ":static_assert",
        ":type_traits",
        ":unordered",
        ":utility",
    ],
)

boost_library(
    name = "iterator",
    hdrs = [
        "boost/function_output_iterator.hpp",
        "boost/generator_iterator.hpp",
        "boost/indirect_reference.hpp",
        "boost/iterator_adaptors.hpp",
        "boost/next_prior.hpp",
        "boost/pointee.hpp",
        "boost/shared_container_iterator.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":detail",
        ":fusion",
        ":static_assert",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "intrusive",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":cstdint",
        ":noncopyable",
        ":static_assert",
    ],
)

boost_library(
    name = "intrusive_ptr",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":detail",
        ":smart_ptr",
    ],
)

boost_library(
    name = "io",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "iostreams",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":bind",
        ":call_traits",
        ":checked_delete",
        ":config",
        ":detail",
        ":function",
        ":integer",
        ":mpl",
        ":noncopyable",
        ":preprocessor",
        ":random",
        ":range",
        ":ref",
        ":regex",
        ":shared_ptr",
        ":static_assert",
        ":throw_exception",
        ":type",
        ":type_traits",
        ":utility",
        "@//third_party/libzstd",
        "@net_zlib_zlib//:zlib",
        "@org_bzip_bzip2//:bz2lib",
        "@org_lzma_lzma//:lzma",
    ],
)

boost_library(
    name = "lexical_cast",
    visibility = ["//visibility:public"],
    deps = [
        ":array",
        ":chrono",
        ":config",
        ":container",
        ":detail",
        ":integer",
        ":limits",
        ":math",
        ":mpl",
        ":noncopyable",
        ":numeric_conversion",
        ":range",
        ":static_assert",
        ":throw_exception",
        ":type_traits",
    ],
)

boost_library(
    name = "limits",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "locale",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "logic",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "math",
    hdrs = [
        "boost/cstdint.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":predef",
        ":throw_exception",
    ],
)

boost_library(
    name = "mem_fn",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "move",
    visibility = ["//visibility:public"],
    deps = [
        ":assert",
        ":detail",
        ":static_assert",
    ],
)

boost_library(
    name = "mp11",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":detail",
    ],
)

boost_library(
    name = "mpl",
    visibility = ["//visibility:public"],
    deps = [
        ":move",
        ":preprocessor",
    ],
)

boost_library(
    name = "multi_index",
    hdrs = [
        "boost/multi_index_container.hpp",
        "boost/multi_index_container_fwd.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":foreach",
        ":serialization",
        ":static_assert",
        ":tuple",
    ],
)

boost_library(
    name = "multiprecision",
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":cstdint",
        ":lexical_cast",
        ":math",
        ":mpl",
        ":predef",
        ":rational",
        ":throw_exception",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "msm",
    visibility = ["//visibility:public"],
    deps = [
        ":any",
        ":bind",
        ":config",
        ":core",
        ":function",
        ":fusion",
        ":mpl",
        ":mp11",
        ":noncopyable",
        ":parameter",
        ":proto",
        ":serialization",
        ":type_traits",
    ],
)

boost_library(
    name = "noncopyable",
)

boost_library(
    name = "none",
    hdrs = [
        "boost/none_t.hpp",
    ],
)

boost_library(
    name = "numeric_conversion",
    hdrs = glob([
        "boost/numeric/conversion/**/*.hpp",
    ]),
    deps = [
        ":config",
        ":detail",
        ":integer",
        ":limits",
        ":mpl",
        ":throw_exception",
        ":type",
        ":type_traits",
    ],
)

boost_library(
    name = "numeric_ublas",
    hdrs = glob([
        "boost/numeric/ublas/**/*.hpp",
    ]),
    deps = [
        ":concept_check",
        ":config",
        ":core",
        ":iterator",
        ":mpl",
        ":noncopyable",
        ":numeric",
        ":range",
        ":serialization",
        ":shared_array",
        ":static_assert",
        ":timer",
        ":type_traits",
        ":typeof",
        ":utility",
    ],
)

boost_library(
    name = "operators",
)

boost_library(
    name = "optional",
    deps = [
        ":assert",
        ":config",
        ":detail",
        ":none",
        ":static_assert",
        ":throw_exception",
        ":type",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "parameter",
    deps = [
        ":mp11",
    ],
)

boost_library(
    name = "predef",
)

boost_library(
    name = "preprocessor",
)

boost_library(
    name = "process",
    deps = [
        ":algorithm",
        ":asio",
        ":config",
        ":filesystem",
        ":fusion",
        ":system",
        ":winapi",
    ],
)

boost_library(
    name = "program_options",
    deps = [
        ":any",
        ":bind",
        ":config",
        ":detail",
        ":function",
        ":iterator",
        ":lexical_cast",
        ":limits",
        ":noncopyable",
        ":shared_ptr",
        ":static_assert",
        ":throw_exception",
        ":tokenizer",
        ":type_traits",
        ":version",
    ],
)

boost_library(
    name = "ptr_container",
    deps = [
        ":assert",
        ":checked_delete",
        ":circular_buffer",
        ":config",
        ":iterator",
        ":mpl",
        ":range",
        ":serialization",
        ":static_assert",
        ":type_traits",
        ":unordered",
        ":utility",
    ],
)

boost_library(
    name = "qvm",
    deps = [
        ":assert",
        ":core",
        ":exception",
        ":static_assert",
        ":throw_exception",
        ":utility",
    ],
)

boost_library(
    name = "random",
    deps = [
        ":assert",
        ":config",
        ":detail",
        ":foreach",
        ":integer",
        ":lexical_cast",
        ":limits",
        ":math",
        ":mpl",
        ":multi_index",
        ":noncopyable",
        ":operators",
        ":range",
        ":regex",
        ":shared_ptr",
        ":static_assert",
        ":system",
        ":throw_exception",
        ":timer",
        ":tuple",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "range",
    deps = [
        ":array",
        ":assert",
        ":concept_check",
        ":config",
        ":detail",
        ":functional",
        ":integer",
        ":iterator",
        ":mpl",
        ":noncopyable",
        ":optional",
        ":preprocessor",
        ":ref",
        ":regex",
        ":static_assert",
        ":tuple",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "ratio",
    deps = [
        ":integer",
    ],
)

boost_library(
    name = "rational",
    deps = [
        ":assert",
        ":call_traits",
        ":config",
        ":detail",
        ":integer",
        ":operators",
        ":static_assert",
        ":throw_exception",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "ref",
    deps = [
        ":config",
        ":core",
        ":detail",
        ":utility",
    ],
)

boost_library(
    name = "regex",
    hdrs = [
        "boost/cregex.hpp",
    ],
    defines = [
        "BOOST_FALLTHROUGH",
    ],
    deps = [
        ":assert",
        ":config",
        ":cstdint",
        ":detail",
        ":exception",
        ":functional",
        ":integer",
        ":limits",
        ":mpl",
        ":predef",
        ":ref",
        ":smart_ptr",
        ":throw_exception",
        ":type_traits",
    ],
)

boost_library(
    name = "scope_exit",
    deps = [
        ":config",
        ":detail",
        ":function",
        ":mpl",
        ":preprocessor",
        ":type_traits",
        ":typeof",
        ":utility",
    ],
)

boost_library(
    name = "scoped_array",
    deps = [
        ":checked_delete",
    ],
)

boost_library(
    name = "scoped_ptr",
    deps = [
        ":checked_delete",
    ],
)

boost_library(
    name = "shared_ptr",
    visibility = ["//visibility:public"],
    deps = [
        ":checked_delete",
    ],
)

boost_library(
    name = "shared_array",
    deps = [
        ":checked_delete",
    ],
)

boost_library(
    name = "signals2",
    deps = [
        ":assert",
        ":bind",
        ":checked_delete",
        ":config",
        ":core",
        ":detail",
        ":function",
        ":iterator",
        ":mpl",
        ":multi_index",
        ":noncopyable",
        ":optional",
        ":parameter",
        ":predef",
        ":preprocessor",
        ":ref",
        ":scoped_ptr",
        ":shared_ptr",
        ":smart_ptr",
        ":swap",
        ":throw_exception",
        ":tuple",
        ":type_traits",
        ":utility",
        ":variant",
        ":visit_each",
    ],
)

boost_library(
    name = "serialization",
    visibility = ["//visibility:public"],
    deps = [
        ":archive",
        ":array",
        ":call_traits",
        ":config",
        ":container_hash",
        ":detail",
        ":function",
        ":operators",
        ":type_traits",
    ],
)

boost_library(
    name = "smart_ptr",
    hdrs = [
        "boost/enable_shared_from_this.hpp",
        "boost/intrusive_ptr.hpp",
        "boost/make_shared.hpp",
        "boost/make_unique.hpp",
        "boost/pointer_to_other.hpp",
        "boost/weak_ptr.hpp",
    ],
    deps = [
        ":align",
        ":core",
        ":predef",
        ":scoped_array",
        ":scoped_ptr",
        ":shared_array",
        ":shared_ptr",
        ":throw_exception",
        ":utility",
    ],
)

boost_library(
    name = "spirit",
    deps = [
        ":optional",
        ":ref",
        ":utility",
    ],
)

boost_library(
    name = "static_assert",
)

boost_library(
    name = "system",
    deps = [
        ":assert",
        ":cerrno",
        ":config",
        ":core",
        ":cstdint",
        ":noncopyable",
        ":predef",
        ":utility",
    ],
)

boost_library(
    name = "swap",
)

boost_library(
    name = "throw_exception",
    deps = [
        ":current_function",
        ":detail",
        ":exception",
    ],
)

boost_library(
    name = "thread",
    srcs = [
        "libs/thread/src/pthread/once.cpp",
        "libs/thread/src/pthread/thread.cpp",
    ],
    hdrs = [
        "libs/thread/src/pthread/once_atomic.cpp",
    ],
    linkopts = ["-lpthread"],
    deps = [
        ":algorithm",
        ":atomic",
        ":bind",
        ":chrono",
        ":config",
        ":core",
        ":date_time",
        ":detail",
        ":enable_shared_from_this",
        ":exception",
        ":function",
        ":io",
        ":lexical_cast",
        ":smart_ptr",
        ":system",
        ":tuple",
        ":type_traits",
    ],
)

boost_library(
    name = "tokenizer",
    hdrs = [
        "boost/token_functions.hpp",
        "boost/token_iterator.hpp",
    ],
    deps = [
        ":assert",
        ":config",
        ":detail",
        ":iterator",
        ":mpl",
        ":throw_exception",
    ],
)

boost_library(
    name = "tribool",
    hdrs = [
        "boost/logic/tribool.hpp",
        "boost/logic/tribool_fwd.hpp",
    ],
    deps = [
        ":config",
        ":detail",
    ],
)

boost_library(
    name = "type",
    deps = [
        ":core",
    ],
)

boost_library(
    name = "type_index",
    deps = [
        ":core",
        ":functional",
        ":throw_exception",
    ],
)

boost_library(
    name = "tti",
    deps = [
        ":config",
        ":function_types",
        ":mpl",
        ":preprocessor",
        ":type_traits",
    ],
)

boost_library(
    name = "type_traits",
    hdrs = [
        "boost/aligned_storage.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":core",
        ":mpl",
        ":static_assert",
    ],
)

boost_library(
    name = "typeof",
    deps = [
        ":config",
        ":detail",
        ":mpl",
        ":preprocessor",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "tuple",
    deps = [
        ":ref",
    ],
)

boost_library(
    name = "unordered",
    hdrs = [
        "boost/unordered_map.hpp",
        "boost/unordered_set.hpp",
    ],
    deps = [
        ":assert",
        ":config",
        ":container",
        ":detail",
        ":functional",
        ":iterator",
        ":limits",
        ":move",
        ":preprocessor",
        ":smart_ptr",
        ":swap",
        ":throw_exception",
        ":tuple",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "utility",
    hdrs = [
        "boost/compressed_pair.hpp",
        "boost/next_prior.hpp",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":config",
        ":detail",
        ":swap",
    ],
)

boost_library(
    name = "uuid",
    deps = [
        ":assert",
        ":config",
        ":core",
        ":detail",
        ":io",
        ":random",
        ":serialization",
        ":static_assert",
        ":throw_exception",
        ":tti",
        ":type_traits",
    ],
)

boost_library(
    name = "variant",
    visibility = ["//visibility:public"],
    deps = [
        ":call_traits",
        ":config",
        ":detail",
        ":functional",
        ":math",
        ":static_assert",
        ":type_index",
        ":type_traits",
        ":utility",
    ],
)

boost_library(
    name = "version",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "visit_each",
)

boost_library(
    name = "timer",
    deps = [
        ":cerrno",
        ":chrono",
        ":config",
        ":cstdint",
        ":io",
        ":limits",
        ":system",
        ":throw_exception",
    ],
)

boost_library(
    name = "numeric",
)

boost_library(
    name = "test",
    exclude_src = glob(["libs/test/src/*.cpp"]),
    deps = [
        ":algorithm",
        ":assert",
        ":bind",
        ":call_traits",
        ":config",
        ":core",
        ":current_function",
        ":detail",
        ":exception",
        ":function",
        ":io",
        ":iterator",
        ":limits",
        ":mpl",
        ":numeric_conversion",
        ":optional",
        ":preprocessor",
        ":smart_ptr",
        ":static_assert",
        ":timer",
        ":type",
        ":type_traits",
        ":utility",
        ":version",
    ],
)

boost_library(
    name = "winapi",
)

boost_library(
    name = "proto",
    deps = [
        ":fusion",
    ],
)

boost_library(
    name = "phoenix",
    deps = [
        ":proto",
    ],
)

boost_library(
    name = "log",
    defines = [
        "BOOST_LOG_WITHOUT_WCHAR_T",
        "BOOST_LOG_USE_STD_REGEX",
        "BOOST_LOG_WITHOUT_DEFAULT_FACTORIES",
        "BOOST_LOG_WITHOUT_SETTINGS_PARSERS",
        "BOOST_LOG_WITHOUT_DEBUG_OUTPUT",
        "BOOST_LOG_WITHOUT_EVENT_LOG",
        "BOOST_LOG_WITHOUT_SYSLOG",
    ],
    exclude_src = [
        "libs/log/src/dump_avx2.cpp",
    ],
    deps = [
        ":asio",
        ":date_time",
        ":filesystem",
        ":interprocess",
        ":locale",
        ":parameter",
        ":phoenix",
        ":random",
        ":spirit",
        ":system",
        ":thread",
        ":variant",
    ],
)

boost_library(
    name = "xpressive",
)

boost_library(
    name = "property_map",
    visibility = ["//visibility:public"],
)

boost_library(
    name = "graph",
    hdrs = [
        "boost/implicit_cast.hpp",
    ],
    deps = [
        ":algorithm",
        ":config",
        ":foreach",
        ":function",
        ":fusion",
        ":iterator",
        ":lexical_cast",
        ":pending",
        ":property_map",
        ":property_tree",
        ":proto",
        ":regex",
        ":smart_ptr",
        ":typeof",
        ":unordered",
        ":xpressive",
    ],
)

boost_library(
    name = "pending",
)

boost_library(
    name = "units",
    deps = [
        ":config",
        ":integer",
        ":math",
        ":mpl",
        ":static_assert",
        ":type_traits",
        ":typeof",
        ":version",
    ],
)

boost_library(
    name = "crc",
)

boost_library(
    name = "lockfree",
    deps = [
        ":parameter",
    ],
)

boost_library(
    name = "accumulators",
    deps = [
        ":numeric",
        ":parameter",
        ":serialization",
    ],
)

boost_library(
    name = "cast",
)

boost_library(
    name = "polymorphic_cast",
)

boost_library(
    name = "implicit_cast",
)

boost_library(
    name = "python",
    srcs = glob([
        "libs/python/src/converter/*.cpp",
        "libs/python/src/object/*.cpp",
    ]),
    deps = [
        ":cast",
        ":config",
        ":detail",
        ":function",
        ":get_pointer",
        ":graph",
        ":implicit_cast",
        ":iterator",
        ":mpl",
        ":mp11",
        ":noncopyable",
        ":numeric",
        ":operators",
        ":parameter",
        ":polymorphic_cast",
        ":ref",
        ":shared_ptr",
        ":smart_ptr",
        ":type",
        ":type_traits",
        "@//bazel/toolchains/python:python3_dev",
    ],
)

boost_library(
    name = "container_hash",
    deps = [
        ":assert",
        ":config",
        ":core",
        ":type_traits",
    ],
)

boost_library(
    name = "dll",
    deps = [
        ":filesystem",
        ":function",
        ":shared_ptr",
        ":system",
    ],
)

boost_library(
    name = "statechart",
    deps = [
        ":assert",
        ":bind",
        ":config",
        ":detail",
        ":function",
        ":intrusive_ptr",
        ":mpl",
        ":noncopyable",
        ":polymorphic_cast",
        ":ref",
        ":smart_ptr",
        ":static_assert",
    ],
)
