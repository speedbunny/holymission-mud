//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild soul.					Sauron.
//
// File:						Started:
//	/players/sauron/guild/soul.c				100696.
//
// Purpose:
//	This soul handles guild commands and gives guild members an
//	identity/individuality.
//
// History of revisions/fixes:
//
// 100696: Sauron: Started programming.
// 180696: Sauron: Created soul.h file for soul/skill interaction.
// 200696: Sauron: Added guild_shadow functionality.
// 210696: Sauron: Added bug catch on actual command as well as bin module.
//                 Added check_guild_shadow() to handle the guild shadow.
//                 Revised layout of header.
//                 Added log notify toggle.
// 220696: Sauron: Moved extra_look() to guild/include/extra_look.h
//                 Implemented setquery.
// 230696: Sauron: Implemented skill system phase 1 (skill_master.c,
//                 skill.h and cmd_functions.c).
//
//----------------------------------------------------------------------------

#ifndef __GUILD_SOUL_C__

#define __GUILD_SOUL_C__

// Preprocessor directives:

#include "/players/sauron/guild/soul/soul.h"		// Soul defs.
#include "/players/sauron/guild/soul/soul_alias.h"	// Soul aliases.
#include "/players/sauron/guild/soul/soul_basic.h"	// Soul id.
#include "/players/sauron/guild/soul/soul_cmd.h"	// Soul cmd system.
#include "/players/sauron/guild/soul/soul_container.h"	// Soul container system.
#include "/players/sauron/guild/soul/soul_look.h"	// Soul 'look'.

// End preprocessor directives.


// Prototypes:

void do_save();
string query_auto_load();
int get();
int drop(string str);
string query_name();
int query_weight();
int query_value();
int guild_soul();
void reset(int arg);
void init();

// End prototypes.


// Global variables:

// Non-static variables - saved in/restored from the player's guild file.

// Static variables - not saved in/restored from the player's guild file.
static string SAVE_FILE,guild_name;
static object me;

// End global variables.


void do_save() {
  save_object(SAVE_FILE);
}

string query_auto_load() {
  if(query_GM(query_tmp("owner")))
    return "/players/sauron/guild/soul:";
}

int get() {
  return 1;
}

int drop(string str) {
  string verb;

  verb=VERB;
  switch(verb) {
    case "give":
      verb="give away";
      break;
    case "sell":
      break;
    case "quit":
      return 1;
      break;
    default:
      verb="drop";
      break;
  }

  printf("You can't %s your robe! You'd be naked!\n",verb);
  return 1;
}

string query_name() {
  return "robe";
}

int query_weight() {
#ifdef __SOUL_CONTAINER_H__
  return soul_weight;
#else
  return 1;
#endif // __SOUL_CONTAINER_H__
}

int query_value() {
  return 0;
}

int guild_soul() {
  return 1;
}

void reset(int arg) {
  if(!arg) {
    guild_name=GM->query_name(GN);
    SAVE_FILE=sprintf("%s/%s/%s",G_SAVE,RNAME(TP)[0..0],RNAME(TP));
#ifdef __SOUL_CONTAINER_H__
    weight_held=0;
    soul_weight=1;
#endif // __SOUL_CONTAINER_H__
    if(!restore_object(SAVE_FILE)) {
#ifdef __SOUL_ALIAS_H__
      init_soul_aliases();
#endif // __SOUL_ALIAS_H__
    }
  }
  do_save();
}

void init() {
  if(query_tmp("owner") && ENV(TO)!=query_tmp("owner")) {
    MOVE(TO,query_tmp("owner"));
    return;		// Don't want people stealing your soul.
  }

  else if(query_tmp("owner") && TP && ENV(TP)==query_tmp("owner")) {
    TP->MOVEP("X",ENV(query_tmp("owner")));
    return;		// Don't want people in your inventory.
  }

  else if(query_tmp("owner") && TP && query_tmp("owner")!=TP)
    return;		// Don't want other people using your soul.

  else if(!query_tmp("owner") && TP) {
    check_guild_shadow();
    set_tmp("owner",TP);
  }
#ifdef __SOUL_CMD_H__
  add_action("_activate","activate");
  add_action("_look","examine");
  add_action("_look","look");
  add_action("do_cmd","",1);
#endif // __SOUL_CMD_H__
}

#endif // __GUILD_SOUL_C__
