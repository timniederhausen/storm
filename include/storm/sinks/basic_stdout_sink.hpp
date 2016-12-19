//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STORM_SINKS_BASICSTDOUTSINK_HPP
#define STORM_SINKS_BASICSTDOUTSINK_HPP

#include <storm/detail/config.hpp>

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <storm/basic_log_sink.hpp>

#include <asioext/file_handle.hpp>

#include <vstl/string_view.hpp>

STORM_NS_BEGIN

class basic_stdout_sink : public basic_log_sink
{
public:
  STORM_DECL basic_stdout_sink(bool use_stderr = false);

  STORM_DECL void open(bool use_stderr = false);
  STORM_DECL void close();
  STORM_DECL bool is_open() const;

  STORM_DECL void write_record(const vstd::string_view& record);

private:
  asioext::file_handle file_;
};

STORM_NS_END

#endif
