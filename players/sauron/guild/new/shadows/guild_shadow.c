//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild generic shadow.				Sauron.
//
// File:						Started:
//	/players/sauron/guild/shadows/guild_shadow.c		180696.
//
// Purpose:
//	Alter the monk's combat amd provide access to other guild features.
//
// History of revisions/fixes:
//
// 180696: Sauron: Started programming.
// 210696: Sauron: Added set/query_owner() handle. I plan to make this object
//                 (and the rest of the guild) use set() and query() for
//                 ease, and to minimise the number of lfuns. That should
//                 come in a couple of days, along with other stuff. :)
//                 Revised layout of header.
// 220696: Sauron: Implemented setquery.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_GEN_SHADOW_C__

#define __GUILD_GEN_SHADOW_C__


// Inherits:

inherit "/obj/std_shadow";
inherit "/players/sauron/guild/include/cmd_functions";

// End inherits.


// Preprocessor directives:

#define TESTING
    
// End preprocessor directives.
    

// Prototypes:

varargs int start_shadow(object who,int tim,string id,int allow_multi);

int set(string what,mixed val);
int unset(string what);
varargs mixed query(string what);

int set_tmp(string what,mixed val);
int unset_tmp(string what);
varargs mixed query_tmp(string what);

void save_guild_soul();
int guild_shadow();

// End prototypes.


// Global variables:

static object shadowed,soul;

// End global variables.


varargs int start_shadow(object who,int time,string id,int allow_multi) {
  int ret;

  ret=std_shadow::start_shadow(who,time,id,allow_multi);
  if(ret==1)
    shadowed=who;
  return ret;
}

#ifdef TESTING
object query_guild_soul() {
  return present("nms",shadowed);
}
#endif // TESTING

int set(string what,mixed val) {
  if(!soul)
#ifdef TESTING
    soul=query_guild_soul();
#else
    soul=(object)shadowed->query_guild_soul();
#endif // TESTING
  return (int)soul->set(what,val);
}

int unset(string what) {
  if(!soul)
#ifdef TESTING
    soul=query_guild_soul();
#else
    soul=(object)shadowed->query_guild_soul();
#endif // TESTING
  return (int)soul->unset(what);
}

varargs mixed query(string what) {
  if(!soul)
#ifdef TESTING
    soul=query_guild_soul();
#else
    soul=(object)shadowed->query_guild_soul();
#endif // TESTING
  return (mixed)soul->query(what);
}

int set_tmp(string what,mixed val) {
  if(!soul)
#ifdef TESTING
    soul=query_guild_soul();
#else
    soul=(object)shadowed->query_guild_soul();
#endif // TESTING
  return (int)soul->set_tmp(what,val);
}

int unset_tmp(string what) {
  if(!soul)
#ifdef TESTING
    soul=query_guild_soul();
#else
    soul=(object)shadowed->query_guild_soul();
#endif // TESTING
  return (int)soul->unset_tmp(what);
}

varargs mixed query_tmp(string what) {
  if(!soul)
#ifdef TESTING
    soul=query_guild_soul();
#else
    soul=(object)shadowed->query_guild_soul();
#endif // TESTING
  return (mixed)soul->query_tmp(what);
}

void save_guild_soul() {
  if(!soul)
#ifdef TESTING
    soul=query_guild_soul();
#else
    soul=(object)shadowed->query_guild_soul();
#endif // TESTING
  return (void)soul->do_save();
}

int guild_shadow() {
  return 1;
}

object query_shadowed() {
  return shadowed;
}

#endif // __GUILD_GEN_SHADOW_C__
