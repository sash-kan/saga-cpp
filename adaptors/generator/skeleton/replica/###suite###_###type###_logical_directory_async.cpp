//  Copyright (c) 2005-2008 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

///////////////////////////////////////////////////////////////////////////////
// This adaptor implements the async functions based on its own synchronous
// functions for testing purposes only. Since there is no principal need
// to do so, we allow these to be 'switched off'.
#if !defined (SAGA_###SUITE###_FILE_ADAPTOR_NO_ASYNCS)

#include <map>
#include <vector>

#include <boost/assert.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/tokenizer.hpp>

#include <saga/saga/exception.hpp>
#include <saga/saga/url.hpp>
#include <saga/saga/adaptors/task.hpp>
#include <saga/saga/file.hpp>

#include <saga/impl/config.hpp>

#include "config.hpp"
#include "logicaldirectory.hpp"
#include "common_helpers.hpp"

///////////////////////////////////////////////////////////////////////////////
namespace ###suite###_###type###
{

  ///////////////////////////////////////////////////////////////////////////////
  // attribute functions
  saga::task
    logical_directory_cpi_impl::async_attribute_exists(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_attribute_exists",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_attribute_exists,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_attribute_is_readonly(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_attribute_is_readonly",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_attribute_is_readonly,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_attribute_is_writable(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_attribute_is_writable",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_attribute_is_writable,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_attribute_is_vector(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_attribute_is_vector",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_attribute_is_vector,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_attribute_is_extended(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_attribute_is_extended",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_attribute_is_extended,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_get_attribute(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_get_attribute",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_get_attribute,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_set_attribute(std::string key, std::string val)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_set_attribute",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_set_attribute,
                                  key, val);
    }

  saga::task
    logical_directory_cpi_impl::async_get_vector_attribute(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_get_vector_attribute",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_get_vector_attribute,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_set_vector_attribute(
        std::string key, std::vector<std::string> val)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_set_vector_attribute",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_set_vector_attribute,
                                  key, val);
    }

  saga::task
    logical_directory_cpi_impl::async_remove_attribute(std::string key)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_remove_attribute",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_remove_attribute,
                                  key);
    }

  saga::task
    logical_directory_cpi_impl::async_list_attributes()
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_list_attributes",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_list_attributes);
    }

  saga::task
    logical_directory_cpi_impl::async_find_attributes(std::string pattern)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_find_attributes",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_find_attributes,
                                  pattern);
    }

  ///////////////////////////////////////////////////////////////////////////////
  // namespace_entry functions
  saga::task
    logical_directory_cpi_impl::async_get_url()
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_get_url",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_get_url);
    }

  saga::task
    logical_directory_cpi_impl::async_get_cwd()
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_get_cwd",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_get_cwd);
    }

  saga::task
    logical_directory_cpi_impl::async_get_name()
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_get_name",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_get_name);
    }

  saga::task logical_directory_cpi_impl::async_is_dir()
  {
    return saga::adaptors::task("logical_directory_cpi_impl::async_is_dir",
                                shared_from_this(), &logical_directory_cpi_impl::sync_is_dir);
  }

  saga::task logical_directory_cpi_impl::async_is_entry()
  {
    return saga::adaptors::task("logical_directory_cpi_impl::async_is_entry",
                                shared_from_this(), &logical_directory_cpi_impl::sync_is_entry);
  }

  saga::task logical_directory_cpi_impl::async_is_link()
  {
    return saga::adaptors::task("logical_directory_cpi_impl::async_is_link",
                                shared_from_this(), &logical_directory_cpi_impl::sync_is_link);
  }

  saga::task logical_directory_cpi_impl::async_remove(int flags)
  {
    return saga::adaptors::task("logical_directory_cpi_impl::async_remove",
                                shared_from_this(), &logical_directory_cpi_impl::sync_remove,
                                flags);
  }

  saga::task
    logical_directory_cpi_impl::async_close(double timeout)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_close",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_close,
                                  timeout);
    }

  ///////////////////////////////////////////////////////////////////////////////
  //  namespace_dir functions
  saga::task
    logical_directory_cpi_impl::async_list(std::string pattern, int flags)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_list",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_list,
                                  pattern, flags);
    }

  saga::task
    logical_directory_cpi_impl::async_find(std::string pattern, int flags)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_find",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_find,
                                  pattern, flags);
    }

  saga::task
    logical_directory_cpi_impl::async_is_link(saga::url entry)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_is_link",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_is_link,
                                  entry);
    }

  saga::task
    logical_directory_cpi_impl::async_exists(saga::url entry)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_exists",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_exists,
                                  entry);
    }

  saga::task
    logical_directory_cpi_impl::async_is_dir(saga::url entry)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_is_dir",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_is_dir,
                                  entry);
    }

  saga::task
    logical_directory_cpi_impl::async_is_entry(saga::url entry)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_is_entry",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_is_entry,
                                  entry);
    }

  saga::task
    logical_directory_cpi_impl::async_get_num_entries()
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_get_num_entries",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_get_num_entries);
    }

  saga::task
    logical_directory_cpi_impl::async_get_entry(std::size_t num)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_get_entry",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_get_entry,
                                  num);
    }

  saga::task
    logical_directory_cpi_impl::async_remove(saga::url entry, int flags)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_remove",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_remove,
                                  entry, flags);
    }

  saga::task
    logical_directory_cpi_impl::async_change_dir(saga::url dir)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_change_dir",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_change_dir,
                                  dir);
    }

  saga::task
    logical_directory_cpi_impl::async_make_dir(saga::url dir, int flags)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_make_dir",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_make_dir,
                                  dir, flags);
    }

  ///////////////////////////////////////////////////////////////////////////////
  // logical_directory functions
  saga::task
    logical_directory_cpi_impl::async_is_file(saga::url entry)
    {
      return saga::adaptors::task("logical_directory_cpi_impl::async_is_file",
                                  shared_from_this(), &logical_directory_cpi_impl::sync_is_file,
                                  entry);
    }

  // saga::task
  // logical_directory_cpi_impl::async_open(saga::name_space::entry & ret,
  //     saga::url entry, int flags)
  // {
  //     typedef void (logical_directory_cpi_impl::*sync_open_type)(
  //         saga::name_space::entry & ret, saga::url entry, int flags);
  //
  //     sync_open_type f = (sync_open_type) &logical_directory_cpi_impl::sync_open;
  //     return saga::adaptors::task("logical_directory_cpi_impl::async_open",
  //         shared_from_this(), f, entry, flags);
  // }
  //
  // saga::task
  // logical_directory_cpi_impl::async_open_dir(saga::name_space::directory & ret,
  //     saga::url entry, int flags)
  // {
  //     typedef void (logical_directory_cpi_impl::*sync_open_dir_type)(
  //         saga::name_space::directory & ret, saga::url entry, int flags);
  //
  //     sync_open_dir_type f = (sync_open_dir_type) &logical_directory_cpi_impl::sync_open_dir;
  //     return saga::adaptors::task("logical_directory_cpi_impl::async_open_dir",
  //         shared_from_this(), f, entry, flags);
  // }

  saga::task
    logical_directory_cpi_impl::async_open(saga::url entry, int flags)
    {
      typedef void (logical_directory_cpi_impl::*sync_open_type)(
          saga::replica::logical_file & ret, saga::url entry, int flags);

      sync_open_type f = (sync_open_type) &logical_directory_cpi_impl::sync_open;
      return saga::adaptors::task("logical_directory_cpi_impl::async_open",
                                  shared_from_this(), f, entry, flags);
    }

  saga::task
    logical_directory_cpi_impl::async_open_dir(saga::url entry, int flags)
    {
      typedef void (logical_directory_cpi_impl::*sync_open_dir_type)(
          saga::replica::logical_directory & ret, saga::url entry, int flags);

      sync_open_dir_type f = (sync_open_dir_type) &logical_directory_cpi_impl::sync_open_dir;
      return saga::adaptors::task("logical_directory_cpi_impl::async_open_dir",
                                  shared_from_this(), f, entry, flags);
    }

  saga::task
    logical_directory_cpi_impl::async_find(
        std::string pattern, std::vector<std::string> patterns, int flags)
    {
      typedef void (logical_directory_cpi_impl::*sync_find_type)(
          std::vector<saga::url> & ret, std::string,
          std::vector<std::string>, int);

      sync_find_type f = (sync_find_type) &logical_directory_cpi_impl::sync_find;
      return saga::adaptors::task("logical_directory_cpi_impl::async_find",
                                  shared_from_this(), f, pattern, patterns, flags);
    }

}   // namespace ###suite###_replica
///////////////////////////////////////////////////////////////////////////////

#endif // SAGA_###SUITE###_FILE_ADAPTOR_NO_ASYNCS

