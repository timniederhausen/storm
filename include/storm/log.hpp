/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_LOG_HPP
#define STORM_LOG_HPP

#include <storm/detail/config.hpp>

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#if defined(STORM_DEBUG) || defined(STORM_LOG_SOURCE_LOCATION)
# include "storm/source_location.hpp"
#endif

#include <fmt/format.h>

STORM_NS_BEGIN

template <class Logger, typename... Args>
void log(Logger& logger, const source_location& caller,
         int severity, fmt::CStringRef format, const Args&... args);

template <class Logger, typename... Args>
void log(Logger& logger, int severity, fmt::CStringRef format,
         const Args&... args);

STORM_NS_END

#if !defined(STORM_DEBUG) && !defined(STORM_LOG_SOURCE_LOCATION)
# define STORM_LOG(logger, severity, format, ...) \
  storm::log(logger, severity, format, ##__VA_ARGS__)
#else
# define STORM_LOG(logger, severity, format, ...)       \
  storm::log(logger, STORM_CURRENT_SOURCE_LOCATION(), \
             severity, format, ##__VA_ARGS__)
#endif

#include "storm/impl/log.hpp"

#endif
