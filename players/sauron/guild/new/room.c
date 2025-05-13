//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild room.					Sauron.
//  
// File:						Started:
//	/players/sauron/guild/room.c				180696.
//
// Purpose:
//	This room handles guild commands as and when required by the soul.
//
// History of revisions/fixes:
//
// 180696: Sauron: Started programming.
//                 Property of no_clean_up so that we don't lose the list
//                 of on-line guild members.
// 210696: Sauron: Revised layout of header.
//
//----------------------------------------------------------------------------

#ifndef __MONK_ROOM_C__
 
#define __MONK_ROOM_C__

// Inherits:

inherit "/guild/guild_room";

// End inherits.


// Preprocessor directives:

#include "/players/sauron/guild/include/include.h"

// End preprocessor directives.


// Prototypes:

varargs int list_filter(object ob,int flag);
void init_list();
void add_member();
void remove_member();
object *query_members(int i,status lvl,status inv);
object handle_soul(object who);
void report_log(string log,string entry,string where);
void reset(int arg);
void init();

// End prototypes.


// Global variables:

static string *give_soul;
static object board;
static mapping guild_list;

// End global variables.


varargs int list_filter(object ob,int flag) {
  if(flag)
    return objectp(ob) && !ob->is_invis_to(TP);
  else
    return objectp(ob);
}

void init_list() {
  if(!guild_list)
    guild_list=([]);
}

void add_member() {
  init_list();

  if(!member(guild_list,TP))
    guild_list[TP]=PO;
}

void remove_member() {
  init_list();

  if(member(guild_list,TP))
    guild_list=m_delete(guild_list,TP);
}

varargs object *query_members(int i,status lvl,status inv) {
  object *ret;
  init_list();

  switch(i) {
    case L_PL:
      return filter_array(m_indices(guild_list),"list_filter",TO,inv);
      break;
    case L_AD:
      ret=filter_array(m_indices(guild_list),"list_filter",TO,inv);
      return filter_array(ret,"guild_level_filter",TO,L_AD,lvl);
      break;
    case L_PR:
      ret=filter_array(m_indices(guild_list),"list_filter",TO,inv);
      return filter_array(ret,"guild_level_filter",TO,L_PR,lvl);
      break;
    case L_LDR:
      ret=filter_array(m_indices(guild_list),"list_filter",TO,inv);
      return filter_array(ret,"guild_level_filter",TO,L_LDR,lvl);
      break;
    case L_GM:
      ret=filter_array(m_indices(guild_list),"list_filter",TO,inv);
      return filter_array(ret,"guild_level_filter",TO,L_GM,lvl);
      break;
    default:
      return ({});
      break;
  }
}

object handle_soul(object who) {
  if(member(guild_list,who))
    return guild_list[who];
}

mapping query_ml() {
  return guild_list;
}

void report_log(string log,string entry,string where) {
  int i;
  object *ob,soul;

  ob=query_members(L_GM,1);
  for(i=0;i<sizeof(ob);i++)
    if(ob[i]->query("guild_log_notify"))
      TELLO(ob[i],
        sprintf("There are new logs in '%s' generated in '/%s' by %s.\n\n%s\n",
                log,where,CRNAME(TP),entry));
}

void reset(int arg) {
  ::reset(arg);
  if(!board) {
    board=clone_object("/players/sauron/guild/clone/board");
    board->set_file("players/sauron/guild/data/boards/guild_room");
    board->set_name("guild");
    board->set_short("The Monk's Guild Board");
    transfer(board,this_object());
  }
  if(!arg) {
    set_light(1);
    set_guild(7);
    short_desc="Monk Guild Room.";
    long_desc=short_desc+"\n";
    dest_dir=({
      "/players/sauron/workroom","sauron",
      "/players/misticalla/workroom","misticalla",
    });
    property=({
      "has_fire",
      "no_clean_up",
      "no_sneak",
      "no_steal",
    });
    give_soul=({
      "sauron","shaitan",
    });
    init_list();
  }
}

void init() {
  ::init();
  if(!member(guild_list,TP) && member_array(RNAME(TP),give_soul)!=-1) {
    object soul;
    soul=CO(G_SOUL);
    TR(soul,TP);
    printf("query_ml() = %O\n",query_ml());
  }
}

#endif // __MONK_ROOM_C__
