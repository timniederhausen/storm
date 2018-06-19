/// @copyright Copyright (c) 2017 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_MINSEVERITYSINKWRAPPER_HPP
#define STORM_SINKS_MINSEVERITYSINKWRAPPER_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

STORM_NS_BEGIN

struct log_record;

template <class WrappedSink>
class min_severity_sink_wrapper : public WrappedSink
{
public:
  template <class... Args>
  min_severity_sink_wrapper(Args&&... args);

  bool can_write(const log_record& rec) const noexcept;

  int min_severity() const noexcept { return min_severity_; }
  void min_severity(int severity) noexcept { min_severity_ = severity; }

private:
  int min_severity_;
};

STORM_NS_END

#include "storm/sinks/impl/min_severity_sink_wrapper.hpp"

#endif
