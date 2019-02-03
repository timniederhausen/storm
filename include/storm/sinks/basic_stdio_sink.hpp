/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SINKS_BASICSTDIOSINK_HPP
#define STORM_SINKS_BASICSTDIOSINK_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "storm/basic_log_sink.hpp"

#include <asioext/file_handle.hpp>

STORM_NS_BEGIN

class basic_stdio_sink : public basic_log_sink
{
public:
  enum use_stderr_type { use_stderr = 0 };
  enum use_stdout_type { use_stdout = 1 };

  STORM_DECL basic_stdio_sink(use_stderr_type);
  STORM_DECL basic_stdio_sink(use_stdout_type);
  STORM_DECL basic_stdio_sink(asioext::file_handle file) noexcept;

  STORM_DECL void open(use_stderr_type);
  STORM_DECL void open(use_stdout_type);
  STORM_DECL void open(asioext::file_handle file) noexcept;
  STORM_DECL void close() noexcept;
  STORM_DECL bool is_open() const noexcept;

  STORM_DECL asioext::file_handle handle() const noexcept;

protected:
  asioext::file_handle file_;
};

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/sinks/impl/basic_stdio_sink.cpp"
#endif

#endif
