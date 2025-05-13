/*-------------------------------------------------------------------------*/
/* FILE : i.c                                                              */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              show his/her inventory.                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main() {
  object ob;
  string str, last_item;

  if(TP->test_dark())
    return 1;
  ob = first_inventory(TP);
  while(ob) {
    str = call_other(ob, "short", 0);
    if(str) {
      writelw(CAP(str) + ".\n");
      last_item = str;
    }
    ob = next_inventory(ob);
  }
  say(TP->RNAME + " checks " + POS + " inventory.\n", 0, TP, "");
  return 1;
}

