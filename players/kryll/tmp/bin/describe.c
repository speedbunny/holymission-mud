/*-------------------------------------------------------------------------*/
/* FILE : describe.c                                                       */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              set their description.                                     */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  if(!stringp(str)) {
    TP->write_description();
    return 1;
  }
  TP->set_description(str);
  TP->write_description();
  return 1;
}
