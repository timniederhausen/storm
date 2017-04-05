/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef STORM_IMPL_BASICLOGGER_HPP
#define STORM_IMPL_BASICLOGGER_HPP

#include "storm/detail/config.hpp"

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <vstl/string_view.hpp>

STORM_NS_BEGIN

namespace detail {

template <class Sink>
void forward_log(void* ptr, fmt::MemoryWriter& w, const log_record& rec)
{
  auto sink = static_cast<Sink*>(ptr);
  sink->format(w, rec);
  sink->write_record(vstd::string_view(w.data(), w.size()));
}

}

template <class Sink>
void basic_logger::register_sink(Sink& sink)
{
  sinks_.push_back({&sink, &detail::forward_log<Sink>});
}

STORM_NS_END

#endif
