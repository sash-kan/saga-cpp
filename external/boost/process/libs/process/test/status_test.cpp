//
// Boost.Process
// Regression tests for the status class.
//
// Copyright (c) 2006 Julio M. Merino Vidal.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt.)
//

#include <boost/filesystem/operations.hpp>
#include <boost/process/status.hpp>
#include <boost/test/unit_test.hpp>

#include "status_base_test.hpp"

namespace bfs = ::boost::filesystem;
namespace bp = ::boost::process;
namespace but = ::boost::unit_test;

// ------------------------------------------------------------------------

but::test_suite *
init_unit_test_suite(int argc, char* argv[])
{
    bfs::initial_path();

    but::test_suite* test = BOOST_TEST_SUITE("status test suite");

    add_tests_status_base< bp::status >(test);

    return test;
}
