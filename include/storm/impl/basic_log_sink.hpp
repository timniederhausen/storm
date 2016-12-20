/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_IMPL_BASICLOGSINK_HPP
#define STORM_IMPL_BASICLOGSINK_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

STORM_NS_BEGIN

namespace detail {

template <class Formatter>
void forward_format(void* ptr, fmt::MemoryWriter& w, const log_record& rec)
{
  (*static_cast<Formatter*>(ptr))(w, rec);
}

}

template <class Formatter>
void basic_log_sink::formatter(Formatter& formatter)
{
  ptr_ = &formatter;
  format_ = &detail::forward_format<Formatter>;
}

STORM_NS_END

#endif
