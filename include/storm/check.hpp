//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STORM_CHECK_HPP
#define STORM_CHECK_HPP

#include <storm/detail/config.hpp>

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#if STORM_DEBUG || STORM_ENABLE_ASSERT
# include <boost/current_function.hpp>
#endif

STORM_NS_BEGIN

/// Handle a check failure.
///
/// This function handles a check failure.
/// It is guranteed that this function never returns control
/// to the caller.
///
/// @param filename Name of the file which contains the expression in question.
///
/// @param lineno Line number in the file.
///
/// @param function Name of the function containing the expression in
/// question.
///
/// @param expr The expression in question.
///
/// @param msg An optional simple error message describing the check.
/// Can be null.
///
/// @return This function never returns. The return
/// value is only here to allow the use of @code (expr) || storm::handle...
/// @endcode
bool handle_check_failure(const char* filename, int lineno,
                          const char* function, const char* expr,
                          const char* msg = nullptr);

STORM_NS_END

#if STORM_DEBUG || STORM_ENABLE_ASSERT
# define STORM_CHECK_MSG(condition, msg) \
    ((condition)) || storm::handle_check_failure(__FILE__, __LINE__, \
                                                 BOOST_CURRENT_FUNCTION, \
                                                 #condition, (msg))
# define STORM_CHECK(condition) STORM_CHECK_MSG(condition, nullptr)
# define STORM_CHECK_OP(name, op, val1, val2) \
    ((val1) op (val2)) || storm::handle_check_failure(__FILE__, __LINE__, \
                                                      BOOST_CURRENT_FUNCTION, \
                                                      #val1 " " #op " " #val2)
# define STORM_DCHECK STORM_CHECK
# define STORM_DCHECK_OP STORM_CHECK_OP
#else
# define STORM_CHECK_MSG(condition, msg) \
    ((condition)) || storm::handle_check_failure(nullptr, 0, nullptr, \
                                                 #condition, (msg))
# define STORM_CHECK(condition) STORM_CHECK_MSG(condition, nullptr)
# define STORM_CHECK_OP(name, op, val1, val2) \
    ((val1) op (val2)) || storm::handle_check_failure(nullptr, 0, nullptr, \
                                                      #val1 " " #op " " #val2)
# define STORM_DCHECK(condition) (void)0
# define STORM_DCHECK_OP(name, op, val1, val2) (void)0
#endif

#define STORM_CHECK_EQ(val1, val2) STORM_CHECK_OP(EQ, ==, val1, val2)
#define STORM_CHECK_NE(val1, val2) STORM_CHECK_OP(NE, !=, val1, val2)
#define STORM_CHECK_LE(val1, val2) STORM_CHECK_OP(LE, <=, val1, val2)
#define STORM_CHECK_LT(val1, val2) STORM_CHECK_OP(LT, < , val1, val2)
#define STORM_CHECK_GE(val1, val2) STORM_CHECK_OP(GE, >=, val1, val2)
#define STORM_CHECK_GT(val1, val2) STORM_CHECK_OP(GT, > , val1, val2)

#define STORM_DCHECK_EQ(val1, val2) STORM_DCHECK_OP(EQ, ==, val1, val2)
#define STORM_DCHECK_NE(val1, val2) STORM_DCHECK_OP(NE, !=, val1, val2)
#define STORM_DCHECK_LE(val1, val2) STORM_DCHECK_OP(LE, <=, val1, val2)
#define STORM_DCHECK_LT(val1, val2) STORM_DCHECK_OP(LT, < , val1, val2)
#define STORM_DCHECK_GE(val1, val2) STORM_DCHECK_OP(GE, >=, val1, val2)
#define STORM_DCHECK_GT(val1, val2) STORM_DCHECK_OP(GT, > , val1, val2)

#endif
