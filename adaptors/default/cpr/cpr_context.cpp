//  Copyright (c) 2005-2009 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 
#include <saga/saga/util.hpp>
#include <saga/saga/exception.hpp>
#include <saga/saga/adaptors/task.hpp>
#include <saga/saga/adaptors/attribute.hpp>

#include "config.hpp"
#include "cpr_context.hpp"

///////////////////////////////////////////////////////////////////////////////
namespace cpr
{

  ///////////////////////////////////////////////////////////////////////////////
  //  constructor
  context_cpi_impl::context_cpi_impl (proxy                * p, 
                                      cpi_info       const & info,
                                      saga::ini::ini const & glob_ini, 
                                      saga::ini::ini const & adap_ini,
                                      TR1::shared_ptr <saga::adaptor> adaptor)
    : base_cpi (p, info, adaptor, cpi::Noflags)
  {
    saga::adaptors::attribute attr (this);

    if ( attr.attribute_exists (saga::attributes::context_type) &&
        attr.get_attribute     (saga::attributes::context_type) != "UserPass" )
    {
        SAGA_OSSTREAM strm;
        strm << "Can't handle context types others than 'UserPass' "
             << "(got: " << attr.get_attribute(saga::attributes::context_type) 
             << ")";
        SAGA_ADAPTOR_THROW(SAGA_OSSTREAM_GETSTRING(strm), saga::adaptors::AdaptorDeclined);
    }
  }

  ///////////////////////////////////////////////////////////////////////////////
  //  destructor
  context_cpi_impl::~context_cpi_impl (void)
  {
  }

  ///////////////////////////////////////////////////////////////////////////////
  void context_cpi_impl::sync_set_defaults (saga::impl::void_t & nul)
  {
    saga::adaptors::attribute attr (this);

    if ( attr.attribute_exists (saga::attributes::context_type) )
    {
      if (attr.get_attribute (saga::attributes::context_type) != "UserPass" )
      {
        SAGA_OSSTREAM strm;
        strm << "Can't handle context types others than 'UserPass' "
             << "(got: " << attr.get_attribute(saga::attributes::context_type) 
             << ")";
        SAGA_ADAPTOR_THROW(SAGA_OSSTREAM_GETSTRING(strm), saga::adaptors::AdaptorDeclined);
      }

      if  ( ! attr.attribute_exists (saga::attributes::context_userid) )
        attr.set_attribute (saga::attributes::context_userid, "anonymous");
      
      if ( ! attr.attribute_exists (saga::attributes::context_userpass) )
        attr.set_attribute (saga::attributes::context_userpass, "anonymous");
    }
  }

} // namespace cpr
///////////////////////////////////////////////////////////////////////////////

