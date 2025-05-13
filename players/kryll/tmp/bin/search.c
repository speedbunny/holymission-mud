/*-------------------------------------------------------------------------*/
/* FILE : search.c                                                         */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              search a room or object.                                   */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  notify_fail(ENV(TP)->id(str) ?
              "You find nothing special.\n" : "Search what?\n");
  return (ENV(TP)->do_ser(str) || ENV(TP)->_search(str));
}


