/*-------------------------------------------------------------------------*/
/* FILE : score.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              see their score and stats.                                 */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main() {
  if(TP->query_ghost()) {
    write("You are a ghost and therefore have no score.\n");
    return 1;
  }

  return (TP->show_score());
}
