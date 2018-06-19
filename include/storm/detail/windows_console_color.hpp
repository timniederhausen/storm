/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_DETAIL_WINDOWSCONSOLECOLOR_HPP
#define STORM_DETAIL_WINDOWSCONSOLECOLOR_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

STORM_NS_BEGIN

namespace detail {

// We use a global to store the last console color, so it can be reset during
// program exit. Otherwise the user's console might stay in the last set color,
// which can be very annoying.
class global_console_color
{
public:
  STORM_DECL global_console_color();
  STORM_DECL ~global_console_color();

  STORM_DECL void push_color(void* handle, uint16_t color);
  STORM_DECL void pop_color();

private:
  void* handle_;
  uint16_t old_color_attrs_;
};

STORM_DECL global_console_color& get_console_color();

struct scoped_console_color
{
  STORM_DECL scoped_console_color(void* handle, uint16_t color);
  STORM_DECL ~scoped_console_color();
};

}

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/detail/impl/windows_console_color.cpp"
#endif

#endif
