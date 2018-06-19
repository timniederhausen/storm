/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_BASICLOGSINK_HPP
#define STORM_BASICLOGSINK_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <fmt/format.h>

#include <functional>

STORM_NS_BEGIN

struct log_record;

class basic_log_sink
{
public:
  STORM_DECL basic_log_sink();

  template <class Formatter>
  void formatter(Formatter&& formatter);

  STORM_DECL bool can_write(const log_record& rec) const noexcept;
  STORM_DECL void format(fmt::MemoryWriter& w, const log_record& rec);

private:
  std::function<void (fmt::MemoryWriter& w, const log_record& rec)> format_;
};

STORM_NS_END

#include "storm/impl/basic_log_sink.hpp"

#if defined(STORM_HEADER_ONLY)
# include "storm/impl/basic_log_sink.cpp"
#endif

#endif
