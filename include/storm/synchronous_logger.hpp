//
// Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STORM_SYNCHRONOUSLOGGER_HPP
#define STORM_SYNCHRONOUSLOGGER_HPP

#include <storm/detail/config.hpp>

#if VSTD_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <storm/basic_logger.hpp>

STORM_NS_BEGIN

typedef basic_logger synchronous_logger;

STORM_NS_END

#endif
