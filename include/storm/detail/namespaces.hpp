//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STORM_DETAIL_NAMESPACES_HPP
#define STORM_DETAIL_NAMESPACES_HPP

#include <storm/detail/config.hpp>

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

// Namespace aliases for commonly used libraries.
namespace boost { namespace asio { } }
namespace boost { namespace chrono { } }

STORM_NS_BEGIN

namespace asio = boost::asio;
namespace chrono = boost::chrono;

STORM_NS_END

#endif
