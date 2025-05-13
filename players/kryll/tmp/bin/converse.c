/*-------------------------------------------------------------------------*/
/* FILE : converse.c                                                       */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              converse with others.                                      */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#include "/sys/player_defs.h"

private static void converse_more(string str) {
  string cmd;

  if(str == "**") {
    write("Ok.\n");
    return;
  }

  if(str[0] == '!') {
    sscanf(str, "!%s", cmd);
    command(cmd, TP);
  }
  else if(str != "") {
    say(lw(TP->RNAME + " says: " + str + "\n"), 0, TP,
        lw(INVNAME + " says: " + str + "\n"));
  }

  write("]");
  input_to("converse_more");
}

int main() {
  write("Give '**' to stop.\n");
  write("]");
  input_to("converse_more");
  return 1;
}

