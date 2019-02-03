/// @copyright Copyright (c) 2019 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_LOGSINKS_HPP
#define STORM_LOGSINKS_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
# pragma once
#endif

#include <vector>

STORM_NS_BEGIN

struct log_record;
class basic_logger;

namespace detail {

struct sink_storage
{
  void* ptr;
  void (*log)(void* ptr, basic_logger& logger, const log_record& rec);
};

template <typename Sink>
void log_to_sink(void* ptr, basic_logger& logger, const log_record& rec)
{
  auto sink = static_cast<Sink*>(ptr);
  if (sink->accepts(rec))
    sink->log(logger, rec);
}

}

/// List of log sinks
class log_sinks
{
  friend class basic_logger;

public:
  // |sink| must live as long as any logger using this log_sinks object.
  template <typename Sink>
  void add(Sink& sink)
  { sinks_.push_back({&sink, &detail::log_to_sink<Sink>}); }

  void clear() { sinks_.clear(); }

private:
  std::vector<detail::sink_storage> sinks_;
};

STORM_NS_END

#endif
