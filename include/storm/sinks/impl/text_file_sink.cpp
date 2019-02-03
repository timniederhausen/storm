/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/sinks/text_file_sink.hpp"

#include "storm/detail/namespaces.hpp"

#include <boost/asio/write.hpp>

STORM_NS_BEGIN

void text_file_sink::log(basic_logger& logger, const log_record& rec)
{
  fmt::memory_buffer out;
  format_(out, logger, rec);
  asio::write(file_, asio::buffer(out.data(), out.size()));
}

STORM_NS_END
