/*-------------------------------------------------------------------------*/
/* FILE : shut.c                                                           */
/*                                                                         */
/* Description : This is armageddon, the shut down daemon, which shuts     */
/*               down the mud. Do not clone this object! Call the function */
/*               "shut" with a number of seconds as an argument.           */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 25 1997  Kryll        Cleaned up this file. Changed levels.
 
*/
inherit "obj/monster";
 
#include "/obj/obj_defs.h"

#define SHOUT(x)  efun::shout(x)
 
int transport_offer;
int moved_yet;
int kill_next;
 
int query_immortal() {
  return 1;
}
 
void move_all_players() {
  object *list;
  int i, sz;
 
  list = users();
  for(sz=sizeof(list), i=0; i<sz; i++)
    if(!list[i]->IMM) {
      TELL(list[i], "You are magically transferred to the shop.\n");
      MOVE(list[i], "room/main_shop");
    }
}
 
void cont_shutting(int seconds) {
  string delay;
  int new_delay;
 
  if(seconds <= 0) {
    SHOUT(cap_name + " shouts: I will reboot now.\n");
    shutdown();
    return;
  }
  if(seconds <= 10 && !moved_yet) {
    moved_yet = 1;
    SHOUT(cap_name + " shouts: Come to the shop and sell your stuff!\n");
    move_all_players();
  } 
  if(seconds <= 240 && !transport_offer) {
    SHOUT(cap_name + " shouts: Tell me if you want a trip to the shop!\n");
    transport_offer = 1;
  }
  new_delay = seconds * 3 / 4 - 10;
  call_out("cont_shutting", seconds - new_delay, new_delay);
  delay = "";
  if(seconds > 59) {
    delay = seconds / 60 + " minutes";
    seconds = seconds % 60;
  }
  if(seconds != 0)
    delay += " " + seconds + " seconds";
  SHOUT(cap_name + " shouts: Game reboot in " + delay + ".\n");
}
 
int shut(int seconds) {
  int i;
 
  if(!intp(seconds)) {
    write("Bad argument\n");
    return 1;
  }
  if(seconds == 0) {
    write("No time given\n");
    return 1;
  }
  set_long("He is firmly concentrated on counting.\n");
  i = remove_call_out("cont_shutting");
  if(i > 0) {
    i = (i + 10) * 4;
    if(i < seconds) {
      write("There was already a shutdown in process, "+i+" seconds.\n");
      seconds = i;
    }
  }
  call_out("cont_shutting", 0, seconds * 60);
  return 1;
}
 
int do_shut(string str) {
  int time; 
 
  if(!TP->query_archwiz()) return 0;
  if(!str || !sscanf(str, "%d", time)) return 1;
  shut(time);
  return 1;
}
 
string query_name() {
  return "armageddon";
}
 
void catch_tell(string str) {
  string who, what;
  object ob;
 
  if(!transport_offer)
    return;
  if(sscanf(str, "%s tells you: %s", who, what) != 2)
    return;
  TP->MOVEP("X#room/main_shop");
}
 
varargs int hit_player(int dam, int kind, mixed *elem) {
  SHOUT("Next player to attack me dies!\n");
  if(kill_next) {
    TP->misc_hit(TP->query_hit_point());
    return 1;
  }
  kill_next = 1;
  return 1;
}
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  kill_next = 0;
  set_name("armageddon");
  set_level(500);
  set_wc(1000);
  set_ac(1000);
  set_hp(100000);
  set_ep(0); /* Herp */
  set_spell_mess1("Armageddon crashes the game.");
  set_spell_mess2("Armageddon crashes the game on your head.");
  set_chance(75);
  set_spell_dam(500);
  set_short("Armageddon the game crasher");
  set_long("He seems to firmly concentrated on counting.\n");
  set_alias("shut");
  set_wimpy(-1);
  mmsgin = "arrives through a rift in the fabric of space";
  move_player("X#room/church");
  is_wizard = 1; /* Herp */
}
 
void init() {
  add_action("do_shut","shut");
}
 

