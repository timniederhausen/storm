/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_DETAIL_WINDOWSVTPENABLER_HPP
#define STORM_DETAIL_WINDOWSVTPENABLER_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <cstdint>

STORM_NS_BEGIN

namespace detail {

// Enables Virtual Terminal Sequences on Windows 10+ by setting
// ENABLE_VIRTUAL_TERMINAL_PROCESSING.
// https://msdn.microsoft.com/en-us/library/mt638032(v=vs.85).aspx
class windows_vtp_enabler
{
public:
  STORM_DECL windows_vtp_enabler();
  STORM_DECL ~windows_vtp_enabler();

private:
  void* out_;
  std::uint32_t old_mode_;
};

}

STORM_NS_END

#if defined(STORM_HEADER_ONLY)
# include "storm/detail/impl/windows_vtp_enabler.cpp"
#endif

#endif
