/*-------------------------------------------------------------------------*/
/* FILE : assist.c                                                         */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              assist another living in combat.                           */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 10 1997  Kryll        Converted to a bin system call.
 
*/
 
#include "/sys/defs.h"
 
int main(string str) {
  object friend, victim;
 
  if(!stringp(str) || str == TP->RNAME) {
    notify_fail("Assist whom ?\n");
    return 0;
  }
 
  friend = present(str, ENV(TP));
 
  if(!objectp(friend))
    write("You can't assist someone who isn't here!\n");
  else if(!living(friend))
    write("But " + str + " is not alive!\n");
  else if(objectp(victim = TP->query_attack())
          && ENV(TP)==ENV(victim))
    write("NO WAY! You are fighting for your life!\n");
  else if(!objectp(victim = friend->query_attack()) || !living(victim))
    write("But " + CAP(str) + " isn't fighting anyone!\n");
  else {
    write("You jump in the fight to assist " + CAP(str) + "!\n");
    say(TP->RNAME + " assists " + CAP(str) + "!\n", friend, TP,
        "Someone assists " + CAP(str) + "!\n");
    TELL(friend, TP->NAME + " assists you!\n");
    TP->attack_object(victim);
    victim->attacked_by(TP);
  }
  return 1;
}
