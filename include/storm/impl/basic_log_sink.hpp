/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_IMPL_BASICLOGSINK_HPP
#define STORM_IMPL_BASICLOGSINK_HPP

#include "storm/detail/config.hpp"

#if STORM_HAS_PRAGMA_ONCE
#pragma once
#endif

STORM_NS_BEGIN

template <class Formatter>
void basic_log_sink::formatter(Formatter&& formatter)
{
  format_ = std::move(formatter);
}

STORM_NS_END

#endif
