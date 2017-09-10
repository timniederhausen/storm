/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/detail/windows_console_color.hpp"

#include <windows.h>

STORM_NS_BEGIN

namespace detail {

global_console_color::global_console_color()
  : handle_(nullptr)
  , old_color_attrs_(0)
{
  // ctor
}

global_console_color::~global_console_color()
{
  if (handle_ != nullptr)
    SetConsoleTextAttribute(handle_, old_color_attrs_);
}

void global_console_color::push_color(void* handle, uint16_t color)
{
  CONSOLE_SCREEN_BUFFER_INFO buffer_info;
  if (!GetConsoleScreenBufferInfo(handle, &buffer_info) ||
      !SetConsoleTextAttribute(handle, color | FOREGROUND_INTENSITY))
    return;

  handle_ = handle;
  old_color_attrs_ = buffer_info.wAttributes;
}

void global_console_color::pop_color()
{
  if (handle_ != nullptr)
    SetConsoleTextAttribute(handle_, old_color_attrs_);
}

global_console_color& get_console_color()
{
  static global_console_color state;
  return state;
}

scoped_console_color::scoped_console_color(void* handle, uint16_t color)
{
  get_console_color().push_color(handle, color);
}

scoped_console_color::~scoped_console_color()
{
  get_console_color().pop_color();
}

}

STORM_NS_END
