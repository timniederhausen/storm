/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_IMPL_LOGGERFACADE_HPP
#define STORM_IMPL_LOGGERFACADE_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/log_record.hpp"

STORM_NS_BEGIN

template <class Logger>
template <typename... Args>
void logger_facade<Logger>::log(const source_location& caller,
                                int severity,
                                fmt::CStringRef format,
                                const Args&... args)
{
  // if (!logger_.check_severity(severity))
  //  return;

  log_record rec;
  rec.severity = severity;
  rec.caller = caller;
  rec.writer.write(format, args...);
  logger_.log(std::move(rec));
}

template <class Logger>
template <typename... Args>
void logger_facade<Logger>::log(int severity,
                                fmt::CStringRef format,
                                const Args&... args)
{
  // if (!logger_.check_severity(severity))
  //  return;

  log_record rec;
  rec.severity = severity;
  rec.writer.write(format, args...);
  logger_.log(std::move(rec));
}

STORM_NS_END

#endif
