/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_LOG_HPP
#define STORM_LOG_HPP

#include <storm/detail/config.hpp>

#if STORM_HAS_PRAGMA_ONCE
# pragma once
#endif

#include "storm/source_location.hpp"

#include <fmt/format.h>

STORM_NS_BEGIN

template <typename Logger, typename... Args>
void log(Logger& logger, const source_location& caller,
         int severity, std::string_view format, const Args&... args);

template <typename Logger, typename... Args>
void log(Logger& logger, int severity, std::string_view format,
         const Args&... args);

STORM_NS_END

#if !defined(STORM_DEBUG) && !defined(STORM_LOG_SOURCE_LOCATION)
# define STORM_LOG(logger, severity, format, ...) do { \
  auto& storm_logger = logger; \
  if (storm_logger.accepts(static_cast<int>(severity))) { \
    storm_logger.log({ \
      static_cast<int>(severity), {}, \
      format, \
      fmt::make_format_args(__VA_ARGS__) \
    }); \
  } } while (false)
#else
# define STORM_LOG(logger, severity, format, ...) do { \
  auto& storm_logger = logger; \
  if (storm_logger.accepts(static_cast<int>(severity))) { \
    storm_logger.log({ \
      static_cast<int>(severity), \
      STORM_CURRENT_SOURCE_LOCATION(), \
      format, \
      fmt::make_format_args(__VA_ARGS__) \
    }); \
  } } while (false)
#endif

#include "storm/impl/log.hpp"

#endif
