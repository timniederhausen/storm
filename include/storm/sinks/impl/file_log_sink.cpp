//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STORM_SINKS_IMPL_FILELOGSINK_CPP
#define STORM_SINKS_IMPL_FILELOGSINK_CPP

#include <storm/sinks/file_log_sink.hpp>

#include <storm/detail/namespaces.hpp>

#include <boost/asio/write.hpp>

STORM_NS_BEGIN

file_log_sink::file_log_sink()
{
  // ctor
}

file_log_sink::file_log_sink(const vstd::string_view& filename)
  : filename_(std::move(filename))
  , file_(filename_.c_str(), asioext::open_flags::access_write |
                             asioext::open_flags::create_always)
{
  // ctor
}

void file_log_sink::open(const vstd::string_view& filename)
{
  assign(filename_, filename);
  file_.open(filename_.c_str(), asioext::open_flags::access_write |
                                asioext::open_flags::create_always);
}

void file_log_sink::close()
{
  // TODO(tim): Clear filename?
  file_.close();
}

bool file_log_sink::is_open() const
{
  return file_.is_open();
}

const vstd::string& file_log_sink::filename() const
{
  return filename_;
}

void file_log_sink::write_record(const vstd::string_view& record)
{
  asio::write(file_, asio::buffer(record.data(), record.size()));
}

STORM_NS_END

#endif
