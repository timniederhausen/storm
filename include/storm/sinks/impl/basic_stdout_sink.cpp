/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/sinks/basic_stdout_sink.hpp"

#include "storm/detail/namespaces.hpp"

#include <asioext/standard_streams.hpp>

#include <boost/asio/write.hpp>

STORM_NS_BEGIN

basic_stdout_sink::basic_stdout_sink(bool use_stderr)
  : file_(use_stderr ? asioext::get_stderr() : asioext::get_stdout())
{
  // ctor
}

void basic_stdout_sink::open(bool use_stderr)
{
  if (use_stderr)
    file_ = asioext::get_stderr();
  else
    file_ = asioext::get_stdout();
}

void basic_stdout_sink::close()
{
  // NOTE: Do NOT close the handle!
  file_ = asioext::file_handle();
}

bool basic_stdout_sink::is_open() const
{
  return file_.is_open();
}

asioext::file_handle basic_stdout_sink::handle() const
{
  return file_;
}

void basic_stdout_sink::write_record(std::string_view record)
{
  asio::write(file_, asio::buffer(record.data(), record.size()));
}

STORM_NS_END
