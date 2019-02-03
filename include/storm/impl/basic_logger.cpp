/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/basic_logger.hpp"

STORM_NS_BEGIN

basic_logger::basic_logger(log_sinks sinks)
  : sinks_(std::move(sinks))
{}

basic_logger::basic_logger(log_sinks sinks, std::string name)
  : sinks_(std::move(sinks))
  , name_(std::move(name))
{}

void basic_logger::log(const log_record& rec)
{
  for (const auto& sink : sinks_.sinks_)
    sink.log(sink.ptr, *this, rec);
}

STORM_NS_END
