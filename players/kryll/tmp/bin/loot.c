/*-------------------------------------------------------------------------*/
/* FILE : loot.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              autoloot corpses.                                          */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 10 1997  Kryll        Converted to a bin system call.
 
*/
 
#include "/sys/defs.h"
 
int main(string str) {
  swicth(str) {
    case "all" :
      TP->setenv("AUTOLOOT", 2);
      write("You start to loot everything off of corpses.\n");
      return 1;
    case "money" :
      TP->setenv("AUTOLOOT", 1);
      write("You start looting only money from corpses.\n");
      return 1;
    case "items" :
      TP->setenv("AUTOLOOT", 3);
      write("You start looting everything from corpses, except money.\n");
      return 1;
    case "none" :
      TP->setenv("AUTOLOOT", 0);
      write("You stop automatically looting corpses.\n");
      return 1;
    default :
      notify_fail("Loot what?\n");
      return 0;
  }
}

