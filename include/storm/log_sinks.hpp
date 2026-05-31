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

#include "storm/basic_log_sink.hpp"

STORM_NS_BEGIN

struct log_record;
class basic_logger;

/// List of log sinks
class log_sinks
{
  friend class basic_logger;

public:
  constexpr log_sinks() noexcept = default;

  log_sinks(const log_sinks&) = delete;
  log_sinks& operator=(const log_sinks&) = delete;

  constexpr log_sinks(log_sinks&& other) noexcept
    : first_(other.first_)
    , last_(other.last_)
  {
    other.first_ = nullptr;
    other.last_ = nullptr;
  }

  log_sinks& operator=(log_sinks&& other) noexcept
  {
    if (this != &other) {
      clear();
      first_ = other.first_;
      last_ = other.last_;
      other.first_ = nullptr;
      other.last_ = nullptr;
    }
    return *this;
  }

  ~log_sinks() { clear(); }

  // |sink| must live as long as any logger using this log_sinks object.
  template <typename Sink>
  void add(Sink& sink)
  {
    if (auto last = last_)
      last->next = &sink.link_;
    last_ = &sink.link_;

    if (!first_)
      first_ = &sink.link_;

    // assert: !sink.link_.ptr
    sink.link_.ptr = &sink;
    sink.link_.log = &detail::log_to_sink<Sink>;
  }

  void clear()
  {
    // clear intrusive list references
    for (auto first = first_; first; ) {
      auto next = first->next;
      static_cast<basic_log_sink*>(first->ptr)->link_ = {};
      first->next = nullptr;
      first = next;
    }

    // clear root pointers
    first_ = nullptr;
    last_ = nullptr;
  }

private:
  detail::sink_storage* first_ = nullptr;
  detail::sink_storage* last_ = nullptr; // this is inclusive, i.e. NOT one-past-last
};

STORM_NS_END

#endif
