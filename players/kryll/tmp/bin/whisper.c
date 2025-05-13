/*-------------------------------------------------------------------------*/
/* FILE : whisper.c                                                        */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              whisper to someone else.                                   */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  object ob;
  string who, msg;

  if(TP->query_ghost()) {
    write("You fail.\n");
    return 1;
  }
  if(!str || sscanf(str, "%s %s", who, msg)!=2) {
    write("Whisper what ?\n");
    return 1;
  }
  who = lower_case(who);
  ob = find_living(who);
  if(!ob || !present(who, ENV(TP))) {
    write("No player with that name in this room.\n");
    return 1;
  }
  TELL(ob, lw(TP->NAME + " whispers to you: " + msg + "\n"));
  writelw("You whisper to " + CAP(who) + ": " + msg + "\n");
  say((TP->NAME + " whispers something to " + who + ".\n"), ob, TP,
      (CAP(who) + " seems to listen carefully.\n"));
  return 1;
}

