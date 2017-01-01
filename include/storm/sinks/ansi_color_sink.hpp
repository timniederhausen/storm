/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_ANSICOLORSINK_HPP
#define STORM_SINKS_ANSICOLORSINK_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#if VSTD_PLATFORM_WINDOWS
# include "storm/detail/windows_vtp_enabler.hpp"
#endif

#include <fmt/format.h>

STORM_NS_BEGIN

struct log_record;

using ansi_color_string = const char*;

template <class WrappedSink>
class ansi_color_sink : public WrappedSink
{
public:
  template <class... Args>
  ansi_color_sink(Args&&... args);

  void color_table(const ansi_color_string* color_table, std::size_t size);

  template <std::size_t N>
  void color_table(const ansi_color_string (&color_table) [N]);

  void format(fmt::MemoryWriter& w, const log_record& rec);

private:
  const ansi_color_string* color_table_;
  std::size_t color_table_size_;

#if VSTD_PLATFORM_WINDOWS
  detail::windows_vtp_enabler vtp_enabler_;
#endif
};

STORM_NS_END

#include "storm/sinks/impl/ansi_color_sink.hpp"

#endif
