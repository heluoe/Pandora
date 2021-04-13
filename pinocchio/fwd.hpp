//
// Copyright (c) 2018-2020 CNRS INRIA
//

#ifndef __pinocchio_fwd_hpp__
#define __pinocchio_fwd_hpp__

// Forward declaration of the main pinocchio namespace
namespace pinocchio
{
}

#ifdef _WIN32
#include <windows.h>
#undef far
#undef near
#endif

// #include "pinocchio/config.hpp"
#include "pinocchio/container/boost-container-limits.hpp"
#include "pinocchio/deprecation.hpp"
#include "pinocchio/macros.hpp"
#include "pinocchio/utils/cast.hpp"
// #include "pinocchio/utils/helpers.hpp"
// #include "pinocchio/warning.hpp"

// Import Eigen and all the required modules
#include "pinocchio/eigen-macros.hpp"

#include <Eigen/Core>
#ifdef PINOCCHIO_WITH_EIGEN_TENSOR_MODULE
#include <unsupported/Eigen/CXX11/Tensor>
#endif

#include <cstddef>  // std::size_t

// #include "pinocchio/core/binary-op.hpp"
// #include "pinocchio/core/unary-op.hpp"

namespace pinocchio
{
///
/// \brief Common traits structure to fully define base classes for CRTP.
///
template <class C>
struct traits
{
};

namespace internal
{
template <typename T>
struct traits
{
};
}  // namespace internal

///
/// \brief Type of the cast of a class C templated by Scalar and Options, to a new NewScalar type.
///        This class should be specialized for each types.
///
template <typename NewScalar, class C>
struct CastType;

/// \brief Argument position.
///        Used as template parameter to refer to an argument.
enum ArgumentPosition
{
    ARG0 = 0,
    ARG1 = 1,
    ARG2 = 2,
    ARG3 = 3,
    ARG4 = 4
};

enum AssignmentOperatorType
{
    SETTO,
    ADDTO,
    RMTO
};

/// \brief Return type undefined
///        This is an helper structure to help internal diagnosis.
struct ReturnTypeNotDefined;
}  // namespace pinocchio

#endif  // #ifndef __pinocchio_fwd_hpp__
