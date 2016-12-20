/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_LOGSINK_HPP
#define STORM_LOGSINK_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <fmt/format.h>

STORM_NS_BEGIN

class source_location;

template <class Logger>
class logger_facade
{
public:
  logger_facade(Logger& logger)
    : logger_(logger)
  {
    // ctor
  }

  template <typename... Args>
  void log(const source_location& caller,
           int severity,
           fmt::CStringRef format,
           const Args&... args);

  template <typename... Args>
  void log(int severity, fmt::CStringRef format, const Args&... args);

private:
  Logger& logger_;
};

STORM_NS_END

#include "storm/impl/logger_facade.hpp"

#endif
