/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_BASICLOGGER_HPP
#define STORM_BASICLOGGER_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/log_sinks.hpp"

#include <string>

STORM_NS_BEGIN

class basic_logger
{
public:
  STORM_DECL basic_logger(log_sinks sinks);
  STORM_DECL basic_logger(log_sinks sinks, std::string name);

  const log_sinks& sinks() const noexcept
  { return sinks_; }

  bool accepts(int severity) const noexcept
  { return true; }

  STORM_DECL void log(const log_record& rec);

private:
  log_sinks sinks_;
  std::string name_;
};

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/impl/basic_logger.cpp"
#endif

#endif
