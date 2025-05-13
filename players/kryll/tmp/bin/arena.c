/*-------------------------------------------------------------------------*/
/* FILE : arena.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              enter the arena.                                           */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#include "/sys/player_defs.h"

int main(string str) {
  switch(str) {
    case "enter" :
      if(ENV(TP) && ENV(TP)->query_property("no_teleport")) {
        write("You cannot enter the arena from here.\n");
      }
      else if(ARENA->allow_enter(TP)) {
        ARENA->arena_shout(CAP(TP->RNAME) + " entered the bloodbath!\n");
        TP->MOVEP("to the arena#" + ARENA);
        hit_point = max_hp;
        spell_points = max_sp;
      }
      else
        write("You are not allowed to join the bloodbath !\n");
      return 1;
    case "champions" :
      ARENA->do_show("champions");
      break;
    case "cheaters" :
      ARENA->do_show("cheaters");
      break;
    default :
      ARENA->show_open(TP);
      break;
  }
  return 1;
}

