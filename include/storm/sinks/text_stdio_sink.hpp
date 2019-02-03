/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_TEXTSTDIOSINK_HPP
#define STORM_SINKS_TEXTSTDIOSINK_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/sinks/basic_stdio_sink.hpp"

#if defined(_WIN32)
# include "storm/detail/windows_vtp_enabler.hpp"
#endif

#include <fmt/format.h>

#include <functional>

STORM_NS_BEGIN

class basic_logger;

using ansi_color_string = const char*;

class text_stdio_sink : public basic_stdio_sink
{
public:
  using format_signature = void (fmt::memory_buffer& out,
                                 basic_logger& logger,
                                 const log_record& rec);

  using basic_stdio_sink::basic_stdio_sink;

  STORM_DECL void color_table(const ansi_color_string* table,
                              std::size_t size) noexcept;

  STORM_DECL void log(basic_logger& logger, const log_record& rec);

  template <class Formatter>
  void formatter(Formatter&& formatter)
  { format_ = std::move(formatter); }

  template <std::size_t N>
  void color_table(const ansi_color_string (&table) [N]) noexcept
  { color_table(table, N); }

private:
  std::function<format_signature> format_;

  const ansi_color_string* color_table_ = nullptr;
  std::size_t color_table_size_; // = 0

#if defined(_WIN32)
  detail::windows_vtp_enabler vtp_enabler_;
#endif
};

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/sinks/impl/basic_stdio_sink.cpp"
#endif

#endif
