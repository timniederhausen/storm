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

template <typename Logger, typename... T>
void log(Logger& logger, const source_location& caller, int severity,
         fmt::format_string<T...> format, T&&... args)
{
  if (logger.accepts(severity)) {
    // TODO: there must be a better way, right?
    const fmt::string_view format_str(format);
    const std::string_view format_str_std(format_str.data(), format_str.size());
    logger.log({severity, caller, format_str_std, fmt::make_format_args(args...)});
  }
}

template <typename Logger, typename... T>
void log(Logger& logger, int severity, fmt::format_string<T...> format, T&&... args)
{
  if (logger.accepts(severity)) {
    // TODO: there must be a better way, right?
    const fmt::string_view format_str(format);
    const std::string_view format_str_std(format_str.data(), format_str.size());
    logger.log({severity, {}, format_str_std, fmt::make_format_args(args...)});
  }
}

STORM_NS_END

#endif
