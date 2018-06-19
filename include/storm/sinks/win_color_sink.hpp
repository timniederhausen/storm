/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_WINCOLORSINK_HPP
#define STORM_SINKS_WINCOLORSINK_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <string_view>

STORM_NS_BEGIN

#if !defined(_WIN32)
# error "Only available on Windows!"
#endif

using win_console_color = uint16_t;

template <class WrappedSink>
class win_color_sink : public WrappedSink
{
public:
  template <class... Args>
  win_color_sink(Args&&... args);

  void color_table(const win_console_color* color_table, std::size_t size);

  void write_record(std::string_view record);

private:
  const win_console_color* color_table_;
  std::size_t color_table_size_;
};

STORM_NS_END

#include "storm/sinks/impl/win_color_sink.hpp"

#endif
