//  Copyright (c) 2005-2008 Andre Merzky
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "saga-shell.hpp"

// print the state of the job
int shell::c_status (std::vector <std::string> & args,
                     props & p)
{
#if !defined(SAGA_HAVE_PACKAGE_JOB)
    carp("saga has been compiled without the job package, unable to use this command");
    return FAILURE;
#endif

  // sanity checks
  if ( args.empty () )
  {
    carp ("format: status <pid> [...]", p);
    return FAILURE;
  }

  std::vector <std::string> :: iterator begin = args.begin ();
  std::vector <std::string> :: iterator end   = args.end ();
  std::vector <std::string> :: iterator iter;

  for ( iter = begin; iter != end; ++iter )
  {
    int pid = atoi (iter->c_str ());

    // get job 
    saga::job::job job = jobs_.get_job (pid);

    // get state
    saga::job::state state = job.get_state ();

    // show state
    p.out += state_to_string (state);
    p.out += "\n";

    // purge old entries
    if ( state == saga::job::Done     ||
         state == saga::job::Failed   ||
         state == saga::job::Canceled )
    {
      jobs_.del (pid);
    }
  }

  return SUCCESS;
}

