/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_DETAIL_CONFIG_HPP
#define STORM_DETAIL_CONFIG_HPP

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

// STORM_MSVC: Expands to the MSVC version (i.e. the _MSC_VER value).
#if !defined(STORM_MSVC)
# if defined(ASIOEXT_HAS_BOOST_CONFIG) && defined(BOOST_MSVC)
#  define STORM_MSVC BOOST_MSVC
# elif defined(_MSC_VER) && (defined(__INTELLISENSE__) \
      || (!defined(__MWERKS__) && !defined(__EDG_VERSION__)))
#  define STORM_MSVC _MSC_VER
# endif
#endif

// STORM_HAS_PRAGMA_ONCE: Support for the '#pragma once' extension.
#if !defined(STORM_HAS_PRAGMA_ONCE)
# if !defined(STORM_DISABLE_PRAGMA_ONCE)
#  if defined(__clang__)
#   define STORM_HAS_PRAGMA_ONCE 1
#  endif
#  if defined(__GNUC__)
#   if ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 4)) || (__GNUC__ > 3)
// GCC supports it, but recent versions(?) seem to have performance
// penalties associated with this: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=58770
//#    define STORM_HAS_PRAGMA_ONCE 1
#   endif
#  endif
#  if defined(STORM_MSVC) && (STORM_MSVC >= 1020)
#   define STORM_HAS_PRAGMA_ONCE 1
#  endif
# endif
#endif

#if STORM_HAS_PRAGMA_ONCE
# pragma once
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
# if defined(DEBUG) || defined(_DEBUG)
#  define STORM_DEBUG 1
# endif
#endif

#endif
