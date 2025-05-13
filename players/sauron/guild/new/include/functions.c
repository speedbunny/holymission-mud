//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild generic finctions.				Sauron.
//
// File:						Started:
//	/players/sauron/guild/include/functions.c		180696.
//
// Purpose:
//	This generic functions file contains all the simple funs needed in
//	the guild.
//
// History of revisions/fixes:
//
// 180696: Sauron: Started programming.
// 210696: Sauron: Revised layout of header.
// 220696: Sauron: Added setquery functionality.
// 230696: Sauron: Added query_guild_level() and interactive checks.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_FUNCTIONS_C__

#define __GUILD_FUNCTIONS_C__

// Preprocessor directives:

#include "/players/sauron/guild/include/include.h"

// End preprocessor directives.


// Prototypes:

varargs int guild_level_filter(string name,int gl,int flag);
varargs mixed query_GM(mixed arg);
varargs mixed query_leader(mixed arg,int flag);
varargs mixed query_creator(mixed arg,int flag);
varargs mixed query_protector(mixed arg,int flag);
varargs mixed query_advanced(mixed arg,int flag);
int query_guild_level(mixed arg);
void guild_log_file(string log,string entry);

// End prototypes.

varargs int guild_level_filter(mixed arg,int gl,int flag) {
  if(objectp(arg))
    arg=CRNAME(arg);
  if(stringp(arg) && arg!="")
    return flag?GUILD_LEVELS[arg]>=gl:GUILD_LEVELS[arg]==gl;
  else
    return 0;
}

varargs mixed query_GM(mixed arg) {
  int ret;
  object ob;

  if(arg) {
    if(objectp(arg)) {
      ob=arg;
      arg=CRNAME(arg);
    }
    else if(stringp(arg) && arg!="") {
      ob=find_player(LOW(arg));
      arg=CAP(arg);
    }

    if(member(GUILD_LEVELS,arg) && interactive(ob))
      ret=(GUILD_LEVELS[arg]==L_GM);

    return ret;
  }
  else
    return filter_array(m_indices(GUILD_LEVELS),"guild_level_filter",TO,L_GM);
}
 
varargs mixed query_leader(mixed arg,int flag) {
  int ret;
  object ob;

  if(arg) {
    if(objectp(arg)) {
      ob=arg;
      arg=CRNAME(arg);
    }
    else if(stringp(arg) && arg!="") {
      ob=find_player(LOW(arg));
      arg=CAP(arg);
    }

    if(member(GUILD_LEVELS,arg) && interactive(ob))
      ret=(flag?(GUILD_LEVELS[arg]>=L_LDR || APPR(ob)):
                 GUILD_LEVELS[arg]==L_LDR);
    return ret;
  }
  else
    return filter_array(m_indices(GUILD_LEVELS),"guild_level_filter",
                        TO,L_LDR,flag);
}
   
varargs mixed query_creator(mixed arg,int flag) {
  int ret;
  object ob;

  if(arg) {
    if(objectp(arg)) {
      ob=arg;
      arg=CRNAME(arg);
    }
    else if(stringp(arg) && arg!="") {
      ob=find_player(LOW(arg));
      arg=CAP(arg);
    }

    if(member(GUILD_LEVELS,arg) && interactive(ob))
      ret=(flag?(member_array(arg,CREATORS)!=-1 || GUILD_LEVELS[arg]==L_GM):
                 member_array(arg,CREATORS)!=-1);
    return ret;
  }
  else
    return CREATORS;
}
   
varargs mixed query_protector(mixed arg,int flag) {
  int ret;
  object ob;

  if(arg) {
    if(objectp(arg)) {
      ob=arg;
      arg=CRNAME(arg);
    }
    else if(stringp(arg) && arg!="") {
      ob=find_player(LOW(arg));
      arg=CAP(arg);
    }

    if(member(GUILD_LEVELS,arg) && interactive(ob))
      ret=(flag?(GUILD_LEVELS[arg]>=L_PR || APPR(ob)):
                 GUILD_LEVELS[arg]==L_PR);
    return ret;
  }
  else
    return filter_array(m_indices(GUILD_LEVELS),"guild_level_filter",
                        TO,L_PR,flag);
}
   
varargs mixed query_advanced(mixed arg,int flag) {
  int ret;

  if(arg) {
    if(stringp(arg) && arg!="")
      arg=find_player(arg);
    if(objectp(arg) && interactive(arg))
      ret=(flag?(LEVEL(arg)>=LVL_AD || APPR(arg)):LEVEL(arg)>=LVL_AD);
    return ret;
  }
  else
    return 0;
}

int query_guild_level(mixed arg) {
  object ob;

  if(!arg)
    return L_PL;

  if(objectp(arg)) {
    ob=arg;
    arg=CRNAME(arg);
  }
  else if(stringp(arg) && arg!="")
    ob=find_player(arg);

  if(!ob || !interactive(ob))
    return L_PL;
  else if(member(GUILD_LEVELS,arg))
    return GUILD_LEVELS[arg];
  else if(LEVEL(ob)>=LVL_AD)
    return L_AD;
  else
    return L_PL;
}
  
void guild_log_file(string log,string entry) {
  mixed *st;
  log=G_LOG+log;
  entry=lwnl(ctime()[4..<6]+": "+entry);
  if(sizeof(st=get_dir(log,7)) && (int)st[0][1]>MAX_LOG_SIZE)
    catch(rename(log,log+".old"));	// No panic if failure
  write_file(log,entry);
  G_ROOM->report_log(log,entry,file_name(this_object()));
  return;
}

#endif // __GUILD_FUNCTIONS_C__
