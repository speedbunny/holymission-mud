/*-------------------------------------------------------------------------*/
/* FILE : tell.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              to tell messages to other players.                         */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

nomask private void tell_player(string str) {
  object ob;
  string who, msg, myname;

  if(!str || sscanf(str, "%s %s", who, msg)!=2) {
    write("The correct syntax is : tell <player> <message> \n");
    return;
  }

  who = lower_case(who);
  ob = find_living(who);
  TP->set_retell_message(msg);
  if(!ob) {
    write("No player with that name.\n");
    return;
  }

  if(ob == TP) {
    write("You talk with yourself, looking quite insane.\n");
    say(TP->NAME + " talks with " + TP->OBJ + "self" +
        ", and looks quite insane.\n");
    return;
  }

  if(query_editing(ob)) {
    write("The poor wizard is using ed. right now. Try later.\n");
    return;
  }

  if(ob->query_earmuff_level() > TP->LVL) {
    write("That person is busy right now, try again later.\n");
    return;
  }

  /* 21-SEP-93 Galadriel: quick fix, check if its an npc like Yorel etc */
  if((int)query_ip_number(ob)) {
    if(ob->query_linkdeath()) {
      write("The player is currently linkdead.\n");
      return;
    }
    if(query_idle(ob) > 300)
      write("That player is idle. Message sent anyway.\n");
  }

  if(query_input_pending(ob)) {
    write("That player is writing something. Message sent anyway.\n");
  }

  if(funcall(call, ob, "is_afk")) {
    write("This player is afk.... message sent anyway...\n");
  }

  if(!TP->IMM && !ob->IMM)
    TP->restore_spell_points(-5);

  /* Matt 6-12-94: tell should not say "Someone" to higherups */
  if(ob->LVL >= TP->LVL)
    myname = CAP(TP->RNAME);
  else
    myname = TP->NAME;

#if 0
  TELL(ob, lw(myname + " tells you: " + msg + "\n"));
#else
  ltell(ob, "tells you:", msg + "\n", TO);
#endif

  writelw("You tell " + CAP(who) + ": " + msg + "\n");
  return;
}

int main(string str) {
  if(TP->query_ghost()) {
    write("You fail.\n");
    return 1;
  }
  if(TP->query_spell_points<0 && !TP->IMM) {
    write("You are low on power.\n");
    return 1;
  }
  tell_player(str);
  return 1;
}

