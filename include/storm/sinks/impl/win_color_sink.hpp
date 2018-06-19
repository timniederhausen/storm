/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_IMPL_WINCOLORSINK_HPP
#define STORM_SINKS_IMPL_WINCOLORSINK_HPP

#include "storm/detail/windows_console_color.hpp"

STORM_NS_BEGIN

template <class WrappedSink>
template <class... Args>
win_color_sink<WrappedSink>::win_color_sink(Args&&... args)
  : WrappedSink(args...)
  , color_table_(nullptr)
{
  // ctor
}

template <class WrappedSink>
void win_color_sink<WrappedSink>::color_table(
    const win_console_color* color_table, std::size_t size)
{
  color_table_ = color_table;
  color_table_size_ = size;
}

template <class WrappedSink>
void win_color_sink<WrappedSink>::write_record(std::string_view record)
{
  if (color_table_ && rec.severity < color_table_size_) {
    detail::scoped_console_color guard(WrappedSink::handle(),
                                       color_table_[rec.severity]);
    WrappedSink::write_record(record);
    return;
  }
  WrappedSink::write_record(record);
}

STORM_NS_END

#endif
