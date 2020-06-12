//  Copyright (c) 2020 ETH Zurich
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>
#include <hpx/cache/config/defines.hpp>
#include <hpx/modules/cache.hpp>

#if defined(HPX_CACHE_HAVE_DEPRECATION_WARNINGS)
#if defined(HPX_MSVC)
#pragma message("The header hpx/cache.hpp is deprecated, \
    please include hpx/modules/cache.hpp instead")
#else
#warning "The header hpx/cache.hpp is deprecated, \
    please include hpx/modules/cache.hpp instead"
#endif
#endif
