/*-------------------------------------------------------------------------*/
/* FILE : bug.c                                                            */
/*                                                                         */
/* Decription : This file is a bin system call that registers bugs from    */
/*              players as they designate them.                            */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 27 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  string who, current_room;

  if(!str) {
    write("Give an argument: an explanation of the bug would be useful.\n");
    return 1;
  }
  current_room = file_name(ENV(TP));
  log_file("BUGS", "\n");
  log_file("BUGS", CAP(TP->RNAME) + " " + ctime() + " (" +
           current_room + "):\n");
  log_file("BUGS", str + "\n");

  if(sscanf(current_room, "players/%s/", who) == 1)
    log_file(who + ".rep", current_room + " " + ctime() +
             "\n" + "Bug " + CAP(TP->RNAME) + "\n" + str + "\n");
  write("Thank you!\n");
  return 1;
}

