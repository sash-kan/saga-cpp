//  Copyright (c) 2008-2009 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <saga/saga.hpp>
#include "saga-advert.hpp"

///////////////////////////////////////////////////////////////////////////////
#if defined(SAGA_HAVE_PACKAGE_ADVERT) && defined(SAGA_HAVE_PACKAGE_NAMESPACE)

void advert_add_entry (saga_tools::common & c,
                       std::string          aname)
{
  // create a new advert entry
  saga::advert::entry e (c.session (), saga::url (aname), 
                         saga::advert::Create | saga::advert::CreateParents);
}

#endif

