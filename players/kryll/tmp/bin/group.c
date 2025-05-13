/*-------------------------------------------------------------------------*/
/* FILE : group.c                                                          */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              group other players.                                       */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

void show_group(object ob) {
  int    i, sz;
  object *followers;

  write("Current group members:\n----------------------\n");
  if(ob->query_grouped())
    write(ob->NAME + " [level " + LVL + "] (leader)\n");
  if(followers=ob->query_followers()) {
    for(sz=sizeof(followers), i=0; i<sz; i++) {
      if(followers[i]->query_grouped())
        write(followers[i]->NAME + " [level " +
              followers[i]->LVL + "]\n");
    }
  }
  return;
}

int main(string str) {
  object groupee, following_whom, *followers;

  following_whom = TP->query_follow_whom();
  if(!stringp(str)) {
    if(!TP->query_grouped()) {
      write("You are not a member of a group!\n");
      return 1;
    }
    if(!following_whom)
      show_group(TP);
    else
      show_group(following_whom);
    return 1;
  }

  if(following_whom) {
    write("You have to be the leader to group someone!\n");
    return 1;
  }

  if(!(groupee=present(str, ENV(TP))) || !interactive(groupee)) {
    write("There is no such player here!\n");
    return 1;
  }

  if(groupee->IMM) {
    write("You are not allowed to group immortals!\n");
    return 1;
  }

  if(groupee->query_ghost()) {
    write("You can't group with dead creatures.\n");
    return 1;
  }

  if(groupee!=TO && (!(followers=TP->query_followers())
                 || member_array(groupee, followers)==-1)) {
    write("That player isn't following you!\n");
    return 1;
  }

  groupee->toggle_grouped();
  return 1;
}

