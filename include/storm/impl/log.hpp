/// @copyright Copyright (c) 2017 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_IMPL_LOG_HPP
#define STORM_IMPL_LOG_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/log_record.hpp"

STORM_NS_BEGIN

template <class Logger, typename... Args>
void log(Logger& logger, const source_location& caller,
         int severity, std::string_view format, const Args&... args)
{
  logger.log({severity, {}, format, fmt::make_format_args(args...)});
}

template <class Logger, typename... Args>
void log(Logger& logger, int severity, std::string_view format,
         const Args&... args)
{
  logger.log({severity, caller, format, fmt::make_format_args(args...)});
}

STORM_NS_END

#endif
