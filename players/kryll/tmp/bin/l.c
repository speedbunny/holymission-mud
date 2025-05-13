/*-------------------------------------------------------------------------*/
/* FILE : l.c                                                              */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              "look".                                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/player_defs.h"

int main(string str) {
  notify_fail("Look at what ?\n");
  if(str)
    return ((PLAYER + "look")->main(str));
  return 0;
}

