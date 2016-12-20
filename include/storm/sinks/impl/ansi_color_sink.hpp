//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STORM_SINKS_IMPL_ANSICOLORSINK_HPP
#define STORM_SINKS_IMPL_ANSICOLORSINK_HPP

STORM_NS_BEGIN

template <class WrappedSink>
template <class... Args>
ansi_color_sink<WrappedSink>::ansi_color_sink(Args&&... args)
  : WrappedSink(args...)
  , color_table_(nullptr)
{
  // ctor
}

template <class WrappedSink>
void ansi_color_sink<WrappedSink>::color_table(const ansi_color_string* color_table, std::size_t size)
{
  color_table_ = color_table;
  color_table_size_ = size;
}

template <class WrappedSink>
void ansi_color_sink<WrappedSink>::format(fmt::MemoryWriter& w,
                                          const log_record& rec)
{
  bool found_color = false;
  if (color_table_ && rec.severity < color_table_size_) {
    w << color_table_[rec.severity];
    found_color = true;
  }

  WrappedSink::format(w, rec);

  if (found_color)
    w << "\033[00m";
}

STORM_NS_END

#endif
