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

basic_file_sink::basic_file_sink(const vstd::string_view& filename)
  : filename_(filename)
  , file_(asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always))
{
  // ctor
}

basic_file_sink::basic_file_sink(const vstd::string_view& filename,
                                 boost::system::error_code& ec)
  : filename_(filename)
  , file_(asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always,
                        asioext::file_perms::create_default,
                        asioext::file_attrs::none, ec))
{
  // ctor
}

void basic_file_sink::open(const vstd::string_view& filename)
{
  assign(filename_, filename);
  file_ = asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always);
}

void basic_file_sink::open(const vstd::string_view& filename,
                           boost::system::error_code& ec)
{
  assign(filename_, filename);
  file_ = asioext::open(filename_.c_str(),
                        asioext::open_flags::access_write |
                        asioext::open_flags::create_always,
                        asioext::file_perms::create_default,
                        asioext::file_attrs::none, ec);
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

const vstd::string& basic_file_sink::filename() const
{
  return filename_;
}

void basic_file_sink::write_record(const vstd::string_view& record)
{
  asio::write(file_, asio::buffer(record.data(), record.size()));
}

STORM_NS_END
