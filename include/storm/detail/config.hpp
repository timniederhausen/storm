/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_DETAIL_CONFIG_HPP
#define STORM_DETAIL_CONFIG_HPP

#include <vstl/detail/config.hpp>

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

// Project's main namespace.
#define STORM_NS_BEGIN namespace storm {
#define STORM_NS_END }

// Default to a header-only implementation. The user must specifically request
// separate compilation by defining either STORM_SEPARATE_COMPILATION or
// STORM_DYN_LINK (as a DLL/shared library implies separate compilation).
#if !defined(STORM_HEADER_ONLY)
# if !defined(STORM_SEPARATE_COMPILATION)
#  if !defined(STORM_DYN_LINK)
#   define STORM_HEADER_ONLY 1
#  endif
# endif
#endif

#if defined(STORM_HEADER_ONLY)
// Define as |inline| so multiple copies of our functions are discarded.
# define STORM_DECL inline
#else
# if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__CODEGEARC__)
#  if defined(STORM_DYN_LINK)
#   if defined(STORM_SOURCE)
#    define STORM_DECL __declspec(dllexport)
#   else
#    define STORM_DECL __declspec(dllimport)
#   endif
#  endif
# endif
#endif

#if !defined(STORM_DECL)
# define STORM_DECL
#endif

#include <boost/cstdint.hpp>

STORM_NS_BEGIN

using boost::int8_t;
using boost::int_least8_t;
using boost::int_fast8_t;
using boost::uint8_t;
using boost::uint_least8_t;
using boost::uint_fast8_t;

using boost::int16_t;
using boost::int_least16_t;
using boost::int_fast16_t;
using boost::uint16_t;
using boost::uint_least16_t;
using boost::uint_fast16_t;

using boost::int32_t;
using boost::int_least32_t;
using boost::int_fast32_t;
using boost::uint32_t;
using boost::uint_least32_t;
using boost::uint_fast32_t;

#ifndef BOOST_NO_INT64_T

using boost::int64_t;
using boost::int_least64_t;
using boost::int_fast64_t;
using boost::uint64_t;
using boost::uint_least64_t;
using boost::uint_fast64_t;

#endif

using boost::intmax_t;
using boost::uintmax_t;

STORM_NS_END

#ifndef STORM_DEBUG
# if defined(DEBUG) || defined(_DEBUG) || VSTD_DEBUG
#  define STORM_DEBUG 1
# endif
#endif

#endif
