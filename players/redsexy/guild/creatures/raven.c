#include "lw.h"
#include "/players/redsexy/guild/obdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

object att;

id(arg) {
  return arg == "raven" || arg == "black raven" ||
    arg == "raven_object";
}

short() { return "A Black Raven"; }
long() { write("A black Raven sitting on your shoulder.\n"); }

init() {
  add_action("rt",   "rt");
  add_action("rpeck", "rpeck");
  add_action("rloc", "rloc");
  add_action("ban",  "ban");
}

get() { return 1; }
drop() { return 1; }

extra_look() {
  return "A Black Raven sits watchfully on " + TP->POS + " shoulder";
}

rt(arg) {
  string player, message;
  object target;
  if(arg && sscanf(arg, "%s %s", player, message) == 2) {
    target = find_player(player);
    if(target) {
      CHECK_ARM();
      CHECK_SP(RT_SP);
      if(target->query_earmuff_level() < TP->LEVEL) {
	write(lw("Your Raven tells " + target->NAME + ":\n" +
	      ">*< " + message + " >*<\n"));
	if (ENV(TP) != ENV(target))
	  say(TP->NAME + "'s Raven flies away, and returns " +
	      "a moment later.\n");
        TELL(target,capitalize(TP->query_real_name())+"'s Raven lands on your "+
	     "shoulder and whispers:\n" +
	     lw("<*> " + message + " <*>\n") +
	     "then returns to " + TP->OBJ + ".\n");
	if(ENV(TP) != ENV(target))
	  TELLRS(ENV(target), "A black Raven lands on " +
		 target->NAME + "'s shoulder, then flies " +
		 "away.\n", target);
	return 1;
      }
      write(target->SNAME + " has shut " +
	    target->OBJ + "self off from you.\n");
      return 1;
    }
    write("Your Raven cannot find " + CAP(player) + ".\n");
    return 1;
  }
  write("Syntax: rt <player> <message>\n");
  return 1;
}

rpeck(arg) {
  object target;
  if(arg) {
    target = find_player(arg);
    if(target) {
      write("Your Raven pecks at " + target->SNAME + ".\n");
      if(ENV(TP) != ENV(target)) {
	TELLRS(ENV(TP), TP->SNAME + "'s Raven flits off " + TP->POS +
	      " shoulder, then returns.\n", TP);
	TELLRS(ENV(target), TP->SNAME + "'s Raven flies in, pecks " +
	       target->SNAME + " in the head, and flies away.\n",
	       TP, target);
      }
      TELL(target, "OUCH! " + TP->NAME + "'s Raven flies in and pecks " +
	   "you in the head!\n");
      return 1;
    }
    write("Your Raven cannot find " + CAP(arg) + ".\n");
    return 1;
  }
  write("Syntax: rpeck <player>\n");
  return 1;
}

rloc(arg) {
  int i;
  object target, inv;
  if(arg) {
    target = find_player(arg);
    if(target) {
      if(target->LEVEL <= TP->LEVEL || TP->query_immortal()) {
	CHECK_ATTACK();
	CHECK_GHOST();
	CHECK_INTOX();
	CHECK_ARM();
	CHECK_SP(RAVEN_LOC_SP);
	write("You send your raven off to find " + target->NAME + ".\n\n");
	if(ENV(target) != ENV(TP)) {
	  TELLRS(ENV(TP), TP->SNAME + "'s Raven flies away, and returns " +
		 "a moment later.\n", TP);
	  TELLRS(ENV(target), TP->SNAME + "'s Raven wheels in the air " +
                 "above you, then is gone.\n", TP);
	}
	inv = all_inventory(ENV(target));
	write("-- Raven --\n");
	ENV(target)->long();
	for(i = 0; i < sizeof(inv); i++)
	  if(inv[i]->SHORT) write(CAP(inv[i]->SHORT) + ".\n");
	return 1;
      }
      write(target->SNAME + "'s level prevents " + target->OBJ + " from " +
	    "being located.\n");
      return 1;
    }
    write("Your Raven cannot find that player.\n");
    return 1;
  }
  write("Syntax: rloc <player>\n");
  return 1;
}

ban(arg) {
  if(id(arg)) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(RAVEN_BAN_SP);
    write("You banish your Raven.\n");
    say(TP->SNAME + " gestures towards " + TP->POS + " Raven, " +
	"banishing it to its own Plane.\n");
    destruct(TO);
    return 1;
  }
}

destroy_me(silent) {
  if(!silent) {
    write("Your Raven vanishes.\n");
    say(TP->SNAME + "'s Raven vanishes.\n");
  }
  destruct(TO);
  return 1;
}
