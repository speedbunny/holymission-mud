/*-------------------------------------------------------------------------*/
/* FILE : title.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              set their own title if they are of the right level.        */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#include "/sys/levels.h"

int main(string str) {
  if(!(TP->IMM || TP->LVL>L_SET_TITLE))
    return 0;
  if(TO != TP) {
    log_file(lw("Title", ctime() + " " + TO->RNAME +
                " got title " + str + " by " + TP->RNAME + "\n"));
  }
  return (TP->set_title(str));
}

