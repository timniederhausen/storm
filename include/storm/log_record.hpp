/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_LOGRECORD_HPP
#define STORM_LOGRECORD_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/source_location.hpp"

#include <fmt/core.h>

#include <string_view>

STORM_NS_BEGIN

struct log_record
{
  int severity;
  source_location caller;
  std::string_view format;
  fmt::format_args args;
};

STORM_NS_END

#endif
