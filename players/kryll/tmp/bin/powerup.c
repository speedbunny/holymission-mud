/*-------------------------------------------------------------------------*/
/* FILE : powerup.c                                                        */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              powerup all armour and weapons.                            */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#inclue "/sys/defs.h"

int main() {
  object *ob;
  int    i, sz;

  ob = all_inventory(TO);
  for(i=0, sz=sizeof(ob); i<sz; i++) {
    if(ob[i]->query_armour())
      command("wear " + ob[i]->NAME, TP);
    else if(ob[i]->query_weapon())
      command("wield "+ ob[i]->NAME, TP);
  }
  write("Powerup complete.\n");
  return 1;
}

