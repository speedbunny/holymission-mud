/*-------------------------------------------------------------------------*/
/* FILE : pray.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              pray to their god.                                         */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  return RLM->do_pray(TP->query_religion(), str);
}

