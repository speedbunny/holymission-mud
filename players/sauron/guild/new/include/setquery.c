//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild setquery file.				Sauron.
//
// File:						Started:
//	/players/sauron/guild/include/setquery.c		220696.
//
// Purpose:
//	This setquery file contains simple set() and query() funs to reduce
//	lfuns/variables in the guild.
//
// History of revisions/fixes:
//
// 220696: Sauron: Started programming.
//                 Calls to set() are transfered to the soul for the save.
// 230696: Sauron: Calls to set_tmp() are now also transfered.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_SETQUERY_C__

#define __GUILD_SETQUERY_C__

// Preprocessor directives:

#include "/players/sauron/guild/include/include.h"

// End preprocessor directives.


// Prototypes:

private void init_setquery();
int set(string what,mixed val);
int unset(string what);
varargs mixed query(string what);

private void init_setquery_tmp();
int set_tmp(string what,mixed val);
int unset_tmp(string what);
varargs mixed query_tmp(string what);

// End prototypes.


// Global variables:

// Non-static variables - saved in/restored from the player's guild file.
mapping setquery;

// Static variables - not saved in/restored from the player's guild file.
static mapping setquery_tmp;

// End global variables.


/* USERDOC:
init_setquery
Format: init_setquery()

Initialises set-able and query-able vars.
*/

private void init_setquery() {
  if(!setquery)
    setquery=([]);
}

/* USERDOC:
set
Format: set(s,m)

Sets the value labeled 's' in the mapping setquery to 'm'. Returns 1 for 
success, 0 for failure.
*/

int set(string what,mixed val) {
  if(!TO->guild_soul()) {
    object soul;
    soul=(object)TP->query_guild_soul();
    return (int)soul->set(what,val);
  }

  else {
    init_setquery();

    setquery[what]=val;
    TO->do_save();
    return 1;
  }
}

/* USERDOC:
unset
Format: unset(s)

Unsets the value labeled 's' in the mapping setquery. Returns 1 if 's' was 
set in setquery.
*/

int unset(string what) {
  if(!TO->guild_soul()) {
    object soul;
    soul=(object)TP->query_guild_soul();
    return (int)soul->unset(what);
  }

  else {
    init_setquery();
    if(member(setquery,what)) {
      setquery=m_delete(setquery,what);
      TO->do_save();
      return 1;
    }
    else
      return 0;
  }
}

/* USERDOC:
query
Format: m=query(s)

This function queries a value from the mapping setquery. It serches for 
the value labeled 's'. If s is not found 0 is returned. If no 's' is given, 
the entire mapping setquery is returned.
*/

varargs mixed query(string what) {
  if(!TO->guild_soul()) {
    object soul;
    soul=(object)TP->query_guild_soul();
    return (mixed)soul->query(what);
  }

  else {
    init_setquery();
    if(!what)
       return setquery;
    else if(member(setquery,what))
       return setquery[what];
    else
       return 0;
  }
}

/* USERDOC:
init_setquery_tmp
Format: init_setquery_tmp()

Initialises static set-able and query-able vars.
*/

private void init_setquery_tmp() {
  if(!setquery_tmp)
    setquery_tmp=([]);
}

/* USERDOC:
set_tmp
Format: set_tmp(s,m)

Sets the value labeled 's' in the mapping setquery_tmp to 'm'. Returns 1 for 
success, 0 for failure.
*/

int set_tmp(string what,mixed val) {
  if(!TO->guild_soul()) {
    object soul;
    soul=(object)TP->query_guild_soul();
    return (int)soul->set_tmp(what,val);
  }

  else {
    init_setquery_tmp();
    setquery_tmp[what]=val;
    return 1;
  }
}

/* USERDOC:
unset_tmp
Format: unset_tmp(s)

Unsets the value labeled 's' in the mapping setquery_tmp. Returns 1 if 's' was 
set in setquery_tmp.
*/

int unset_tmp(string what) {
  if(!TO->guild_soul()) {
    object soul;
    soul=(object)TP->query_guild_soul();
    return (int)soul->unset_tmp(what);
  }

  else {
    init_setquery_tmp();
    if(member(setquery_tmp,what)) {
      setquery_tmp=m_delete(setquery_tmp,what);
      return 1;
    }
    else
      return 0;
  }
}

/* USERDOC:
query_tmp
Format: m=query_tmp(s)

This function queries a value from the mapping setquery_tmp. It serches for 
the value labeled s. If s is not found 0 is returned. If no s is given, 
the entire mapping setquery_tmp is returned.
*/

varargs mixed query_tmp(string what) {
  if(!TO->guild_soul()) {
    object soul;
    soul=(object)TP->query_guild_soul();
    return (mixed)soul->query_tmp(what);
  }

  else {
    init_setquery_tmp();
    if(!what)
      return setquery_tmp;
    else if(member(setquery_tmp,what))
      return setquery_tmp[what];
    else
      return 0;
  }
}

#endif // __GUILD_SETQUERY_C__
