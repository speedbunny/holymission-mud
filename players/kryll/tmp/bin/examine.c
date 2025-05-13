/*-------------------------------------------------------------------------*/
/* FILE : examine.c                                                        */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              examine an item. It is an alternative form of "look at".   */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/player_defs.h"

int main(string str) {
  notify_fail("Examine what ?\n");
  if(str)
    return ((PLAYER + "look")->main("at " + str));
  return 0;
}

