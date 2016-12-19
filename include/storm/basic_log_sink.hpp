//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STORM_BASICLOGSINK_HPP
#define STORM_BASICLOGSINK_HPP

#include <storm/detail/config.hpp>

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <fmt/format.h>

STORM_NS_BEGIN

struct log_record;

class basic_log_sink
{
public:
  STORM_DECL basic_log_sink();

  template <class Formatter>
  void formatter(Formatter& formatter);

  STORM_DECL void format(fmt::MemoryWriter& w, const log_record& rec);

private:
  void* ptr_;
  void (*format_)(void* ptr, fmt::MemoryWriter& w, const log_record& rec);
};

STORM_NS_END

#include <storm/impl/basic_log_sink.hpp>

#endif
