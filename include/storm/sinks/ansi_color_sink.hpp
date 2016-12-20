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

#include <vstl/string_view_fwd.hpp>

STORM_NS_BEGIN

using ansi_color_string = const char*;

template <class WrappedSink>
class ansi_color_sink : public WrappedSink
{
public:
  template <class... Args>
  ansi_color_sink(Args&&... args);

  void color_table(const ansi_color_string* color_table, std::size_t size);

  void format(fmt::MemoryWriter& w, const log_record& rec);

private:
  const ansi_color_string* color_table_;
  std::size_t color_table_size_;
};

STORM_NS_END

#include "storm/sinks/impl/ansi_color_sink.hpp"

#endif
