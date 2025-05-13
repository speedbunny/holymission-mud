/*-------------------------------------------------------------------------*/
/* FILE : get.c                                                            */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              get an item or items. It uses the take.c call so that only */
/*              one file is needed.                                        */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/player_defs.h"

int main(string str) {
  notify_fail("Get what ?\n");
  if(str)
    return ((PLAYER + "take")->main(str));
  return 0;
}

