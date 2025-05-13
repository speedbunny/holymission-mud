/*-------------------------------------------------------------------------*/
/* FILE : rid.c                                                            */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              to rid themself of someone who is following them.          */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int main(string str) {
  int    i, sz;
  object rid, *followers;

  if(!stringp(str)) {
    write("Who do you want to get rid of ?\n");
    return 1;
  }
  if(rid = TP->query_rid_whom()) {
    write("You try to get rid of " + rid->RNAME + ".\n");
    return 1;
  }
  if(followers = TP->query_followers())
    for(sz=sizeof(followers), i=0; i<sz; i++)
      if(followers[i]->id(str)) {
        TP->set_rid_follower(followers[i]);
        rid = followers[i];
        break;
      }
  if(!rid)
    write("No such living thing is following you!\n");
  else
    write("From now on you'll try to get rid of " + rid->RNAME + ".\n");
  return 1;
}

