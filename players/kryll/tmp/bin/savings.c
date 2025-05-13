/*-------------------------------------------------------------------------*/
/* FILE : savings.c                                                        */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              see their saving throws and resistances.                   */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  write(base_savings_info());
  return 1;
}

