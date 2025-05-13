/*-------------------------------------------------------------------------*/
/* FILE : speak.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              speak in different languages. It should be gone.           */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#include "/sys/living_defs.h"

int main(string str) {
  int i;

  if(!str) {
    write("Languages:\n-------------------------------\n");
    for(i=0; i<NO_OF_LANG; i++)
      printf("%-15s %15s\n", TP->language_name(i),
                             TP->language_skill_name(language_skill(i)));
    write("\nYou are speaking in: " + TP->language_name(speaks_in()));
    write("\n-------------------------------\n");
    return 1;
  }
  if(str == "common")
    TP->set_speaks_in(0);
  else if(str == "nihonese")
    TP->set_speaks_in(1);
  else {
    write("There is no such language.\n");
    return 1;
  }
  write("You will now speak in " + str + ".\n");
  return 1;
}

