/*-------------------------------------------------------------------------*/
/* FILE : say.c                                                            */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              speak to other players or objects.                         */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 30 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  string verb;

  verb = query_verb();
  if(str == 0)
    str = "";
  if(verb[0] == 39)
    str = extract(verb, 1) + (str ? " " : "") + str;

#if 0
  say(lw(TP->RNAME + " says: " + str + "\n"), 0, TP,
      lw(INVNAME + " says: " + str + "\n"));
#else
  lsay("says:", str + "\n", TP, TP);
#endif

  writelw("You say: " + str + "\n");
  return 1;
}

