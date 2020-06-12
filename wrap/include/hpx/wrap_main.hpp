//  Copyright (c) 2007-2014 Hartmut Kaiser
//  Copyright (c)      2018 Nikunj Gupta
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>
#include <hpx/wrap/config/defines.hpp>
#include <hpx/hpx_init.hpp>

// We support different implementation depending upon the Operating
// System in use.
#if defined(HPX_HAVE_DYNAMIC_HPX_MAIN) && \
    (defined(__linux) || defined(__linux__) || defined(linux) || \
    defined(__APPLE__))

#include <string>

namespace hpx_start
{
    // include_libhpx_wrap here is an override for the one present in
    // src/hpx_wrap.cpp. The value of this variable defines if we need
    // to change the program's entry point or not.
    HPX_SYMBOL_EXPORT extern bool include_libhpx_wrap;
    HPX_SYMBOL_EXPORT bool include_libhpx_wrap = true;
    HPX_SYMBOL_EXPORT extern std::string app_name_libhpx_wrap;
    HPX_SYMBOL_EXPORT std::string app_name_libhpx_wrap = HPX_APPLICATION_STRING;
}

#else

#if defined(HPX_HAVE_STATIC_LINKING)
#include <hpx/wrap_main_impl.hpp>
#endif

// We support redefining the plain C-main provided by the user to be executed
// as the first HPX-thread (equivalent to hpx_main()). This is implemented by
// a macro redefining main, so we disable it by default.
#define main hpx_startup::user_main
#endif

