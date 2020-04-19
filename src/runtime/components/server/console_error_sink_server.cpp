//  Copyright (c) 2007-2016 Hartmut Kaiser
//  Copyright (c)      2011 Bryce Lelbach
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/config.hpp>
#include <hpx/errors.hpp>
#include <hpx/custom_exception_info.hpp>
#include <hpx/runtime_configuration/ini.hpp>
#include <hpx/lcos/base_lco_with_value.hpp>
#include <hpx/runtime/actions/continuation.hpp>
// This is needed to get rid of an undefined reference to
// hpx::actions::detail::register_remote_action_invocation_count
#include <hpx/runtime/actions/transfer_action.hpp>
#include <hpx/runtime/actions/transfer_continuation_action.hpp>
#include <hpx/runtime/components/server/console_error_sink.hpp>
#include <hpx/runtime/components/server/console_error_sink_singleton.hpp>
#include <hpx/util/serialize_exception.hpp>

#include <exception>

///////////////////////////////////////////////////////////////////////////////
namespace hpx { namespace components { namespace server
{
    ///////////////////////////////////////////////////////////////////////////
    // implementation of this console error sink
    void console_error_sink(std::exception_ptr const& e)
    {
        // dispatch this error to registered functions
        get_error_dispatcher()(hpx::diagnostic_information(e));
    }
}}}

///////////////////////////////////////////////////////////////////////////////
// This must be in global namespace
HPX_REGISTER_ACTION_ID(
    hpx::components::server::console_error_sink_action,
    console_error_sink_action,
    hpx::actions::console_error_sink_action_id)

