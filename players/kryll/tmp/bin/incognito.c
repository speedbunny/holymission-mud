/*-------------------------------------------------------------------------*/
/* FILE : incognito.c                                                      */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              toggle between being incognito and not.                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main() {
  status val;

  val = TP->query_incognito();
  if(val) {
    TP->set_incognito(0);
    write("Title now incognito.\n");
  }
  else {
    TP->set_incognito(1);
    write("Title now visible.\n");
  }
  TP->fix_short();
  return 1;
}
