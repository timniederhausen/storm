/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_LOCKINGLOGGER_HPP
#define STORM_LOCKINGLOGGER_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/basic_logger.hpp"

#include <mutex>

STORM_NS_BEGIN

template <class WrappedLogger>
class locking_logger : public WrappedLogger
{
public:
  template <class... Args>
  locking_logger(Args&&... args);

  void unregister_all_sinks();

  void log(const log_record& rec);

private:
  std::mutex mutex_;
};

STORM_NS_END

#include "storm/impl/locking_logger.hpp"

#endif
