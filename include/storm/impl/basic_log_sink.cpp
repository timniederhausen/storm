/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/basic_log_sink.hpp"

#include <limits>

STORM_NS_BEGIN

basic_log_sink::basic_log_sink()
  : min_severity_((std::numeric_limits<int>::min)())
  , max_severity_((std::numeric_limits<int>::max)())
{}

STORM_NS_END
