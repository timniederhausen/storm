/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/basic_log_sink.hpp"
#include "storm/check.hpp"

#include <fmt/format.h>

STORM_NS_BEGIN

basic_log_sink::basic_log_sink()
  : ptr_(nullptr)
  , format_(nullptr)
{
  // ctor
}

void basic_log_sink::format(fmt::MemoryWriter& w, const log_record& rec)
{
  STORM_DCHECK(format_ != nullptr);
  STORM_DCHECK(ptr_ != nullptr);
  format_(ptr_, w, rec);
}

STORM_NS_END
