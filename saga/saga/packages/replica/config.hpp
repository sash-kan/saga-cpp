//  Copyright (c) 2005-2009 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef SAGA_IMPL_PACKAGES_DATA_REPLICA_CONFIG_HPP
#define SAGA_IMPL_PACKAGES_DATA_REPLICA_CONFIG_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

// For symbol import/export macros
#include <saga/saga-defs.hpp>

#if !defined (SAGA_CREATE_PREPROCESSED_FILES)

# ifdef SAGA_REPLICA_PACKAGE_EXPORTS
#   define SAGA_REPLICA_PACKAGE_EXPORT SAGA_SYMBOL_EXPORT
#   define SAGA_REPLICA_PACKAGE_EXPORT_REPEAT SAGA_SYMBOL_EXPORT_REPEAT
#   define SAGA_REPLICA_PACKAGE_LOCAL  SAGA_SYMBOL_INTERNAL
# elif !defined(BUILD_SAGA_LITE)
#   define SAGA_REPLICA_PACKAGE_EXPORT SAGA_SYMBOL_IMPORT
#   define SAGA_REPLICA_PACKAGE_EXPORT_REPEAT /**/
#   define SAGA_REPLICA_PACKAGE_LOCAL  SAGA_SYMBOL_INTERNAL
# else
#   define SAGA_REPLICA_PACKAGE_EXPORT /* empty */
#   define SAGA_REPLICA_PACKAGE_EXPORT_REPEAT /**/
#   define SAGA_REPLICA_PACKAGE_LOCAL  /* empty */
# endif

#endif // !SAGA_CREATE_PREPROCESSED_FILES

#endif // SAGA_IMPL_PACKAGES_DATA_REPLICA_CONFIG_HPP

