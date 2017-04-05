/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_BASICLOGGER_HPP
#define STORM_BASICLOGGER_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <fmt/format.h>

#include <vector>

STORM_NS_BEGIN

struct log_record;

class basic_logger
{
public:
  template <class Sink>
  void register_sink(Sink& sink);

  STORM_DECL void unregister_all_sinks();

  STORM_DECL void log(const log_record& rec);

private:
  struct sink_storage
  {
    void* ptr;
    void (*log)(void* ptr, fmt::MemoryWriter& w, const log_record& rec);
  };

  std::vector<sink_storage> sinks_;
};

STORM_NS_END

#include "storm/impl/basic_logger.hpp"

#if defined(STORM_HEADER_ONLY)
# include "storm/impl/basic_logger.cpp"
#endif

#endif
