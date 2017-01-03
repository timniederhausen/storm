/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_SOURCELOCATION_HPP
#define STORM_SOURCELOCATION_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

STORM_NS_BEGIN

class source_location
{
public:
  constexpr source_location()
    : line_(0)
    , filename_(nullptr)
    , function_name_(nullptr)
  {
    // ctor
  }

  constexpr source_location(uint32_t line,
                            const char* filename,
                            const char* function_name)
    : line_(line)
    , filename_(filename)
    , function_name_(function_name)
  {
    // ctor
  }

  constexpr uint32_t line() const { return line_; }
  constexpr const char* filename() const { return filename_; }
  constexpr const char* function_name() const { return function_name_; }

private:
  uint32_t line_;
  const char* filename_;
  const char* function_name_;
};

constexpr bool empty(const source_location& location)
{
  return location.line() == 0;
}

STORM_NS_END

#define STORM_CURRENT_SOURCE_LOCATION() \
  storm::source_location(__LINE__, __FILE__, __FUNCTION__)

#endif
