/*-------------------------------------------------------------------------*/
/* FILE : smell.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              smell odors in a room or object.                           */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  object who;

  if(str) {
    if(!(who=present(str)) && !(who=present(str, ENV(TP)))) {
      notify_fail("Smell what?\n");
      return 0;
    }
    if(!who->query_smell()) {
      notify_fail("You smell nothing special.\n");
      return 0;
    }
    writelw((string)who->query_smell() + "\n");
    if(who == TP) {
      say(TP->NAME + " smells " + TP->OBJ + "self.\n", 0, TP, "");
      return 1;
    }
    say(TP->NAME + " smells " + CAP(str) + ".\n", who, TP, "");
    TELL(who, (string)TP->NAME + " smells you.\n");
    return 1;
  }
  say(TP->NAME + " tastes the air.\n", 0, TP, "");
  if(!ENV(TP)->query_room("smell")) {
    notify_fail("You smell nothing special.\n");
    return 0;
  }
  writelwnl((string)ENV(TP)->query_room("smell"));
  return 1;
}
 
