/*-------------------------------------------------------------------------*/
/* FILE : junk.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              junk an item in his/her possession.                        */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 27 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  int    value;
  object item;

  if(!str) {
    notify_fail("Junk what ?\n");
    return 0;
  }
  item = present(str, TP);
  if(!item || !stringp(item->short())) {
    notify_fail("Junk what ?\n");
    return 0;
  }
  if(objectp(item->query_wielded())) {
    notify_fail("First you have to unwield your " + str + ".\n");
    return 0;
  }
  if(objectp(item->query_worn())) {
    notify_fail("First you have to remove your " + str + ".\n");
    return 0;
  }

  value = item->query_value();
  if(value > 0)
    value /= 10;
  if(value > 100)
    value = 100;

  write("You junk the " + str + ".\n");
  say(TP->NAME + " junks " + TP->POS + " " + str + ".\n");
// need to transfer first?
  destruct(item);
  if(value > 0) {
    write("You are rewarded for keeping your environment tidy.\n");
    TP->add_money(value);
  }
  return 1;
}

