//  Copyright (c) 2005-2009 Hartmut Kaiser
//  Copyright (c) 2005-2006 Andre Merzky (andre@merzky.net)
//  Copyright (c) 2005-2006 Chris Miceli (cmicel1@cct.lsu.edu)
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#if !defined(SAGA_TEST_DIR_API_HPP)
#define SAGA_TEST_DIR_API_HPP

#include <boost/bind.hpp>
#include <boost/futures.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/for_each.hpp>
#include "../test_saga.hpp"
#include "../macros.hpp"

///////////////////////////////////////////////////////////////////////////////
namespace test_dir
{
 namespace api
 {
    struct equipment 
    {
        saga::url dir;
        saga::test::test_helper_utils *utils;
    };
    
    ///////////////////////////////////////////////////////////////////////////
    struct PlainSync {};
    typedef boost::mpl::vector<
            saga::task_base::Sync, saga::task_base::Async,
            saga::task_base::Task, PlainSync
        > apitypes;

    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    inline void wait_on_futures(boost::futures::future<int> current)
    {
        current();
    }

    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    template <typename TestFunctor, typename E, typename Threaded>
    struct call_test_exception
    {
        call_test_exception(equipment equipment)
          : equipment_(equipment) {}

        typedef int result_type;
        template <typename Tag>
        int operator()(Tag)
        {
            saga::error err = (saga::error)E::value;
            equipment_.dir = equipment_.utils->create_temp_dir_for_exception(
                    (saga::error)E::value).get_url();
            SAGA_REQUIRE_THROW(TestFunctor::test(Tag(), E(), equipment_), err);
            if(err != (saga::error)E::value)
            {
              std::string message;
              message += "Test " + TestFunctor::name + " with exception "
                                   + std::string(saga::error_names[err])
                                   + " expecting " + std::string(saga::error_names[E::value])
                                   + " with threading ";
              if(boost::is_same<Threaded, boost::mpl::true_>::value)
                message += "on";
              else
                message += "off";
              message += " with api_type ";
              if(boost::is_same<Tag, saga::task_base::Sync>::value)
                message += "Sync";
              else if(boost::is_same<Tag, saga::task_base::Async>::value)
                message += "Async";
              else if(boost::is_same<Tag, saga::task_base::Task>::value)
                message += "Task";
              else if(boost::is_same<Tag, PlainSync>::value)
                message += "Plain";
              BOOST_ERROR(message.c_str());
            }
            equipment_.utils->delete_temp_dir(equipment_.dir);
            return 0;
        }
        equipment equipment_;
    };
    ///////////////////////////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////////////////////////
    template <typename TestFunctor, typename E, typename Threaded>
    struct call_test;
   
    template <typename TestFunctor, typename E>
    struct call_test<TestFunctor, E, boost::mpl::true_>
    {
        call_test(equipment equipment, 
                std::vector<boost::futures::future<int> > &futures)
          : equipment_(equipment), futures_(futures){}

        template <typename Tag>
        void operator()(Tag)
        {
            boost::futures::simple_future<int> f(
                boost::bind(call_test_exception<TestFunctor, E, boost::mpl::true_>(equipment_), Tag()));
            futures_.push_back(f);
        }
        equipment equipment_;
        std::vector<boost::futures::future<int> > &futures_;
    };

    template <typename TestFunctor, typename E>
    struct call_test<TestFunctor, E, boost::mpl::false_>
    {
        call_test(equipment equipment)
          : equipment_(equipment) {}

        template <typename Tag>
        void operator()(Tag)
        {
            boost::bind(call_test_exception<TestFunctor, E, boost::mpl::false_>(equipment_), Tag())();
        }
        equipment equipment_;
    };
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    template <typename TestFunctor, typename Threaded>
    struct api_test;
    
    template <typename TestFunctor>
    struct api_test<TestFunctor, boost::mpl::true_>
    {
        api_test(equipment equipment)
          : equipment_(equipment) {}

        // The error is from the list of error_codes defined in the test 
        // structure the api_test is instantiated with
        template <typename Error>
        void operator()(Error)
        {
            std::vector<boost::futures::future<int> > futures;
            boost::mpl::for_each<apitypes>(
                call_test<TestFunctor, Error, boost::mpl::true_>(
                 equipment_, futures));
            std::for_each(futures.begin(), futures.end(), wait_on_futures);
        }
        equipment equipment_;
    };
    
    template <typename TestFunctor>
    struct api_test<TestFunctor, boost::mpl::false_>
    {
        api_test(equipment equipment)
          : equipment_(equipment) {}

        // The error is from the list of error_codes defined in the test 
        // structure the api_test is instantiated with
        template <typename Error>
        void operator()(Error)
        {
            boost::mpl::for_each<apitypes>(
                call_test<TestFunctor, Error, boost::mpl::false_>(
                 equipment_));
        }
        equipment equipment_;
    };
    ///////////////////////////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////////////////////////
    template <typename TestFunctor>
    struct run_test
    {
        static void execute(equipment equipment_)
        {
            // run tests in a non-futurized manner
            boost::mpl::for_each<typename TestFunctor::error_codes>(
                api_test<TestFunctor, boost::mpl::false_>(equipment_));

            // run tests in a futurized manner (highly parallel)
            boost::mpl::for_each<typename TestFunctor::error_codes>(
                api_test<TestFunctor, boost::mpl::true_>(equipment_));
        }
    };
 } // api    
} // test_dir

#endif // !SAGA_TEST_DIR_API_HPP
