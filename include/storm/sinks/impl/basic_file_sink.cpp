/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/sinks/basic_file_sink.hpp"

#include "storm/detail/namespaces.hpp"

#include <asioext/open.hpp>

#include <boost/asio/write.hpp>

STORM_NS_BEGIN

basic_file_sink::basic_file_sink()
{
  // ctor
}

basic_file_sink::basic_file_sink(std::string filename)
  : filename_(std::move(filename))
  , file_(asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always |
                        asioext::open_flags::exclusive_write))
{
  // ctor
}

basic_file_sink::basic_file_sink(std::string filename,
                                 boost::system::error_code& ec)
  : filename_(std::move(filename))
  , file_(asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always |
                        asioext::open_flags::exclusive_write, ec))
{
  // ctor
}

void basic_file_sink::open(std::string_view filename)
{
  filename_ = filename;
  file_ = asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always |
                        asioext::open_flags::exclusive_write);
}

void basic_file_sink::open(std::string_view filename,
                           boost::system::error_code& ec)
{
  filename_ = filename;
  file_ = asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always |
                        asioext::open_flags::exclusive_write, ec);
}

void basic_file_sink::close()
{
  // TODO(tim): Clear filename?
  file_.close();
}

bool basic_file_sink::is_open() const
{
  return file_.is_open();
}

const std::string& basic_file_sink::filename() const
{
  return filename_;
}

STORM_NS_END
