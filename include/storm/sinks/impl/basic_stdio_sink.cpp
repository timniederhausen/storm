/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/sinks/basic_stdio_sink.hpp"

#include <asioext/standard_streams.hpp>

STORM_NS_BEGIN

basic_stdio_sink::basic_stdio_sink(use_stderr_type)
  : file_(asioext::get_stderr())
{}

basic_stdio_sink::basic_stdio_sink(use_stdout_type)
  : file_(asioext::get_stdout())
{}

basic_stdio_sink::basic_stdio_sink(asioext::file_handle file) noexcept
  : file_(file)
{}

void basic_stdio_sink::open(use_stderr_type)
{
  // NOTE: Do NOT close the handle!
  file_ = asioext::get_stdout();
}

void basic_stdio_sink::open(use_stdout_type)
{
  // NOTE: Do NOT close the handle!
  file_ = asioext::get_stdout();
}

void basic_stdio_sink::open(asioext::file_handle file) noexcept
{
  // NOTE: Do NOT close the handle!
  file_ = file;
}

void basic_stdio_sink::close() noexcept
{
  // NOTE: Do NOT close the handle!
  file_ = asioext::file_handle();
}

bool basic_stdio_sink::is_open() const noexcept
{
  return file_.is_open();
}

asioext::file_handle basic_stdio_sink::handle() const noexcept
{
  return file_;
}

STORM_NS_END
