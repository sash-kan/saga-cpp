#  Copyright (c) 2005-2006 Andre Merzky (andre@merzky.net)
# 
#  Distributed under the Boost Software License, Version 1.0. (See accompanying
#  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

SAGA_ROOT         = ../../../

SAGA_SRC          = $(wildcard *.cpp)
SAGA_ADD_BIN_OBJ  = $(SAGA_SRC:%.cpp=%.o)
SAGA_BIN          = saga-isn
SAGA_MAN1         = saga-isn.1

include $(SAGA_ROOT)/make/saga.application.mk

SAGA_CPPINCS     += -I../common
SAGA_LDFLAGS     += -L../common -lsaga_tools_common
