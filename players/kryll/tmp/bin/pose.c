/*-------------------------------------------------------------------------*/
/* FILE : pose.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              pose to all. Kind of worthless i think.                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 27 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  if(TP->LVL >= 15) {
    write("You send a ball of fire into the sky.\n");
    say(TP->RNAME + " makes a magical gesature.\n", 0, TP, "");
    say("A ball of fire explodes in the sky.\n");
    return 1;
  }
  return 0;
}

