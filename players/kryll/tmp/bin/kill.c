/*-------------------------------------------------------------------------*/
/* FILE : kill.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              attack another living.                                     */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

/*--------------------------------------------------------------------------*/
/* Why is everyone trying to kill everything else?                          */
/*--------------------------------------------------------------------------*/
int main(string str) {
  object ob, room;

  if(ghost)
    return 0;
  if(!stringp(str)) {
    write("Kill what ?\n");
    return 1;
  }
  ob = present(lower_case(str), ENV(TP));

  if(!objectp(ob)) { 
    write("No " + str + " here!\n");
    return 1;
  }
  if(!living(ob)) { 
    write(str + " is not a living thing !\n");
    say(TP->NAME + " tries foolishly to attack " + str + ".\n");
    return 1;
  }

  if(attacker_ob) {
    write("You are already busy fighting !\n");
    return 1;
  }

  if(room = ENV(TP)) {
    if(room->query_property("no_fight")) {
      write("You are not allowed to fight here.\n");
      TELL(ob, TP->NAME + " tried to attack you.\n");
      room->try_attack(TP);
      return 1;
    }
  }
  attack_object(ob);
  return 1;
}

