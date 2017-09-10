/// @copyright Copyright (c) 2017 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_IMPL_MINSEVERITYSINKWRAPPER_HPP
#define STORM_SINKS_IMPL_MINSEVERITYSINKWRAPPER_HPP

#include "storm/log_record.hpp"

STORM_NS_BEGIN

template <class WrappedSink>
template <class... Args>
min_severity_sink_wrapper<WrappedSink>::min_severity_sink_wrapper(
    Args&&... args)
  : WrappedSink(args...)
  , min_severity_(0)
{
  // ctor
}

template <class WrappedSink>
bool min_severity_sink_wrapper<WrappedSink>::can_write(
    const log_record& rec) const noexcept
{
  return rec.severity >= min_severity_;
}

STORM_NS_END

#endif
