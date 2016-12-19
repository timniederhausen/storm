//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <storm/basic_logger.hpp>

#include <fmt/format.h>

STORM_NS_BEGIN

void basic_logger::log(const log_record& rec)
{
  fmt::MemoryWriter w;
  for (const auto& sink : sinks_) {
    sink.log(sink.ptr, w, rec);
    w.clear();
  }
}

STORM_NS_END
