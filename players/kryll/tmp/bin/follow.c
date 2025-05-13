/*-------------------------------------------------------------------------*/
/* FILE : follow.c                                                         */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              follow somebody else.                                      */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  object whom, current_whom;

  if(!stringp(str)) {
    if(!(current_whom = TP->query_follow_whom())) {
      write("Follow whom ?\n");
      return 1;
    }

    if(current_whom == TP) {
      writelw("You are not allowed to follow yourself. Take some "+
              "initiative in life!\n");
      TP->rem_follower(current_whom);
      return 1;
    }

    write("You stop following " + current_whom->NAME + ".\n");
    TELL(current_whom, TP->NAME + " stops following you.\n");
    current_whom->rem_follower(TP);
    current_whom = grouped = 0;
    return 1;
  }

  if(!ENV(TP) || !(whom=present(str, ENV(TP))) || !living(whom)) {
    write("There is no such living thing here!\n");
    return 1;
  }

  if(whom->query_rid_whom() == TP) {
    write("You can't refollow at the moment.\n");
    return 1;
  }

  if(!query_ip_number(whom)) {
    write("You can only follow players!\n");
    return 1;
  }
  if(!whom->set_follower(TP)) {
    write("Sorry, following in loops is not allowed!\n");
  }
  else if(!TP->IMM) {
    write("You start following " + whom->NAME + ".\n");
    TELL(whom, TP->NAME + " starts following you.\n");
    follow_whom = whom;
  }
  return 1;
}

