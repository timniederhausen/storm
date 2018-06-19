/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_IMPL_LOCKINGLOGGER_HPP
#define STORM_IMPL_LOCKINGLOGGER_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/log_record.hpp"

STORM_NS_BEGIN

template <class WrappedLogger>
template <class... Args>
locking_logger<WrappedLogger>::locking_logger(Args&&... args)
  : WrappedLogger(args...)
{
  // ctor
}

template <class WrappedLogger>
void locking_logger<WrappedLogger>::unregister_all_sinks()
{
  std::lock_guard<std::mutex> guard(mutex_);
  WrappedLogger::unregister_all_sinks();
}

template <class WrappedLogger>
void locking_logger<WrappedLogger>::log(const log_record& rec)
{
  std::lock_guard<std::mutex> guard(mutex_);
  WrappedLogger::log(rec);
}

STORM_NS_END

#endif
