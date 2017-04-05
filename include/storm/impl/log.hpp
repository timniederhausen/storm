/// @copyright Copyright (c) 2017 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_IMPL_LOG_HPP
#define STORM_IMPL_LOG_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/log_record.hpp"

STORM_NS_BEGIN

template <class Logger, typename... Args>
void log(Logger& logger, const source_location& caller,
         int severity, fmt::CStringRef format, const Args&... args)
{
  log_record rec;
  rec.severity = severity;
  rec.caller = caller;
  rec.writer.write(format, args...);
  logger.log(std::move(rec));
}

template <class Logger, typename... Args>
void log(Logger& logger, int severity, fmt::CStringRef format,
         const Args&... args)
{
  log_record rec;
  rec.severity = severity;
  rec.writer.write(format, args...);
  logger.log(std::move(rec));
}

STORM_NS_END

#endif
