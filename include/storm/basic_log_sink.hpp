/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_BASICLOGSINK_HPP
#define STORM_BASICLOGSINK_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/log_record.hpp"

STORM_NS_BEGIN

class basic_log_sink
{
public:
  STORM_DECL basic_log_sink();

  bool accepts(const log_record& rec) const noexcept
  { return rec.severity >= min_severity_ && rec.severity <= max_severity_; }

  void min_severity(int min_severity) noexcept { min_severity_ = min_severity; }
  void max_severity(int max_severity) noexcept { max_severity_ = max_severity; }

private:
  int min_severity_;
  int max_severity_;
};

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/impl/basic_log_sink.cpp"
#endif

#endif
