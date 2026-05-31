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

#include <climits>

STORM_NS_BEGIN

class basic_logger;

namespace detail {

// our very simple polymorphism for sinks - avoid the extra vtable cache miss
struct sink_storage
{
  void* ptr = nullptr;
  void (*log)(void* ptr, basic_logger& logger, const log_record& rec) = nullptr;
  sink_storage* next = nullptr;
};

template <typename Sink>
void log_to_sink(void* ptr, basic_logger& logger, const log_record& rec)
{
  auto sink = static_cast<Sink*>(ptr);
  if (sink->accepts(rec))
    sink->log(logger, rec);
}

}

class basic_log_sink
{
  friend class log_sinks;
public:
  constexpr basic_log_sink() = default;

  bool accepts(const log_record& rec) const noexcept
  { return rec.severity >= min_severity_ && rec.severity <= max_severity_; }

  void min_severity(int min_severity) noexcept { min_severity_ = min_severity; }
  void max_severity(int max_severity) noexcept { max_severity_ = max_severity; }

private:
  // XXX: This couples the sink to at most one log_sinks.
  // Turns out to be quite reasonable in the way we use it.
  detail::sink_storage link_;

  int min_severity_ = INT_MIN;
  int max_severity_ = INT_MAX;
};

STORM_NS_END

#endif
