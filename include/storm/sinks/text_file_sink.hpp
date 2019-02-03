/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_TEXTFILESINK_HPP
#define STORM_SINKS_TEXTFILESINK_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/sinks/basic_file_sink.hpp"

#include <asioext/unique_file_handle.hpp>

#include <boost/system/error_code.hpp>

#include <fmt/format.h>

#include <functional>

STORM_NS_BEGIN

class basic_logger;

class text_file_sink : public basic_file_sink
{
public:
  using format_signature = void (fmt::memory_buffer& out,
                                 basic_logger& logger,
                                 const log_record& rec);

  using basic_file_sink::basic_file_sink;

  STORM_DECL void log(basic_logger& logger, const log_record& rec);

  template <class Formatter>
  void formatter(Formatter&& formatter)
  { format_ = std::move(formatter); }

private:
  std::function<format_signature> format_;
};

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/sinks/impl/text_file_sink.cpp"
#endif

#endif
