/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#include "storm/detail/windows_vtp_enabler.hpp"

#include <windows.h>

STORM_NS_BEGIN

namespace detail {

#if !defined(ENABLE_VIRTUAL_TERMINAL_PROCESSING)
static const DWORD ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004;
#endif

windows_vtp_enabler::windows_vtp_enabler()
  : out_(GetStdHandle(STD_OUTPUT_HANDLE))
  , old_mode_(0xffffffff)
{
  if (out_ == INVALID_HANDLE_VALUE)
    return;

  DWORD old_out_mode = 0;
  if (!GetConsoleMode(out_, &old_out_mode))
    return;

  const DWORD new_mode = old_out_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;

  // Seems like ENABLE_VIRTUAL_TERMINAL_PROCESSING is already set.
  // Do nothing in this case (most likely there's another windows_vtp_enabler
  // object somewhere).
  if (new_mode == old_out_mode)
    return;

  if (!SetConsoleMode(out_, new_mode))
    return;

  old_mode_ = old_out_mode;
}

windows_vtp_enabler::~windows_vtp_enabler()
{
  if (old_mode_ != 0xffffffff)
    SetConsoleMode(out_, old_mode_);
}

}

STORM_NS_END
