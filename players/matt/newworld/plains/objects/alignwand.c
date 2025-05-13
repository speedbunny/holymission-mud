#include "/players/matt/defs.h"

id(arg) {
  return arg == "wand" || arg == "magic wand";
}

short() {
  return "Green wand";
}

long() {
  write("This is a slim, greenish wand with a red tip. There is some\n");
  write("writing along its length.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 5000; }

init() {
  add_action("read", "read");
  add_action("strike", "strike");
}

read(arg) {
  if(id(arg) || arg == "writing") {
    if(present("spectacles", TP)) {
      write("The wand reads:\n");
      write("  This Wand of Alignment allows you to possess a living\n");
      write("  creature and change its alignment. Simply strike the\n");
      write("  desired creature with the wand to effect the change.\n");
      write("  The wand will only influence those of low intellect.\n");
      return 1;
    }
    write("You cannot understand the writing.\n");
    return 1;
  }
} 

strike(arg) {
  string creature;
  object target;
  if(arg && sscanf(arg, "%s with wand", creature)) {
    target = present(creature, ENV(TP));
    if(target && living(target)) {
      if(target->INT < 10) {
	write("You strike " + target->NAME + " with the wand.\n");
	say(TP->NAME + " strikes " + target->NAME + " with a " +
	    "magic wand.\n");
	if(target->query_alignment() == 0) {
	  TELLR(ENV(TP), "Nothing happens.\n");
	  return 1;
	}
	if(target->query_alignment() < 0) {
	  TELLR(ENV(TP), target->NAME + " suddenly looks nicer.\n");
	  target->set_al(- target->query_alignment());
	  target->set_long(target->NAME + " has a blank domesticated " +
			   "look in its eyes.\n");
	  target->set_aggressive(0);
	  return 1;
	}
	TELLR(ENV(TP), target->NAME + " suddenly looks nastier.\n");
	target->set_al(- target->query_alignment());
	target->set_long("The " + target->NAME + "'s eyes glow with an " +
			 "unholy red light.\n");
	target->set_aggressive(1);
	return 1;
      }
      write("That creature is far too intelligent to be influenced.\n");
      return 1;
    }
    write("You cannot change " + CAP(creature) + "'s alignment.\n");
    return 1;
  }
}
