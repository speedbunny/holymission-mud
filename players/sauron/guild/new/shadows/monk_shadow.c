//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild generic shadow.				Sauron.
//
// File:						Started:
//	/players/sauron/guild/shadows/monk_shadow.c		180696.
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

#ifndef __MONK_GEN_SHADOW_C__

#define __MONK_GEN_SHADOW_C__


// Inherits:

inherit "/obj/std_shadow";
inherit "/players/sauron/guild/include/cmd_functions";

// End inherits.


// Preprocessor directives:
    
// End preprocessor directives.
    

// Prototypes:

varargs int start_shadow(object who,int tim,string id,int allow_multi);

status set(string what,mixed val);
status unset(string what);
varargs mixed query(string what);

status set_tmp(string what,mixed val);
status unset_tmp(string what);
varargs mixed query_tmp(string what);

void save_guild_soul();
status monk_shadow();

// End prototypes.


// Global variables:

static object shadowed,soul;

// End global variables.


varargs int start_shadow(object who,int tim,string id,int allow_multi) {
  int ret;
  if((ret=std_shadow::start_shadow(who,tim,id,allow_multi))==1)
    shadowed=who;
  return ret;
}

object query_guild_soul() {
  return present("nms",this_player());
}

status set(string what,mixed val) {
  if(!soul)
//    soul=(object)shadowed->query_guild_soul();
    soul=query_guild_soul();
  if(soul)
    return soul->set(what,val);
}

status unset(string what) {
  if(!soul)
//    soul=(object)shadowed->query_guild_soul();
    soul=query_guild_soul();
  if(soul)
    return soul->unset(what);
}

varargs mixed query(string what) {
  if(!soul)
//    soul=(object)shadowed->query_guild_soul();
    soul=query_guild_soul();
  if(soul)
    return soul->query(what);
}

status set_tmp(string what,mixed val) {
  if(!soul)
//    soul=(object)shadowed->query_guild_soul();
    soul=query_guild_soul();
  if(soul)
    return soul->set_tmp(what,val);
}

status unset_tmp(string what) {
  if(!soul)
//    soul=(object)shadowed->query_guild_soul();
    soul=query_guild_soul();
  if(soul)
    return soul->unset_tmp(what);
}

varargs mixed query_tmp(string what) {
  if(!soul)
//    soul=(object)shadowed->query_guild_soul();
    soul=query_guild_soul();
  if(soul)
    return soul->query_tmp(what);
}

void save_guild_soul() {
  if(soul)
    return soul->do_save();
}

status monk_shadow() {
  return 1;
}

object query_shadowed() {
  return shadowed;
}

#endif // __MONK_GEN_SHADOW_C__
