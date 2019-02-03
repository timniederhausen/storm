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
{
  auto handle = ::GetStdHandle(STD_OUTPUT_HANDLE);

  DWORD old_out_mode = 0;
  if (!::GetConsoleMode(handle, &old_out_mode)) {
    handle_ = nullptr;
    old_mode_ = 0;
    return;
  }

  const DWORD new_mode = old_out_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;

  // Seems like ENABLE_VIRTUAL_TERMINAL_PROCESSING is already set.
  // Do nothing in this case (most likely there's another windows_vtp_enabler
  // object somewhere).
  if (new_mode == old_out_mode) {
    handle_ = nullptr;
    old_mode_ = ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    return;
  }

  if (!::SetConsoleMode(handle, new_mode)) {
    handle_ = nullptr;
    old_mode_ = 0;
    return;
  }

  handle_ = handle;
  old_mode_ = old_out_mode;
}

windows_vtp_enabler::~windows_vtp_enabler()
{
  if (handle_)
    ::SetConsoleMode(handle_, old_mode_);
}

void windows_vtp_enabler::reset()
{
  if (handle_) {
    ::SetConsoleMode(handle_, old_mode_);
    handle_ = nullptr;
  }
}

bool windows_vtp_enabler::colors_enabled() const noexcept
{
  // 1) we have a handle_ => we enabled VT ourselves
  // 2) old_mode_ == EVT => someone else already did it
  return handle_ || old_mode_ == ENABLE_VIRTUAL_TERMINAL_PROCESSING;
}

}

STORM_NS_END
