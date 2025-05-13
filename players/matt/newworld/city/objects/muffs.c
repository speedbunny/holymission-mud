inherit "/obj/thing";

#include "/players/matt/defs.h"

int mufflevel, worn;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("muffs");
  set_alias("earmuffs");
  set_long("A pair of fluffy black earmuffs that allow you to block out\n" +
	   "unwanted communication. Just type 'muffs <level>' to block out\n" +
	   "/players <level> and below, and 'muffs' to see what levels you\n" +
	   "are currently blocking.\n" +
	   "NOTE: The maximum value for <level> is your current level.\n\n" +
	   "Enjoy!     - Matt\n");
  set_weight(1);
  set_value(2000);
}

short() {
  string temp;
  temp = "";
  if(worn) temp = " (worn)";
  return "Earmuffs (any)" + temp;
}

init() {
  ::init();
  add_action("muffs", "muffs");
  add_action("mywear", "wear");
  add_action("myremove", "remove");
}

muffs(arg) {
  int level;
  if(!arg) {
    if(!mufflevel) {
      write("You are not wearing your earmuffs.\n");
      return 1;
    }
    write("Your earmuffs currently block players level " + mufflevel +
	  " and below.\n");
    return 1;
  }
  if(sscanf(arg, "%d", level)) {
    if(level == 0) {
      if(mufflevel != 0) {
	worn = 0;
	TP->listen_shout(0);
	mufflevel = 0;
       	write("You remove your earmuffs.\n");
	say(TP->NAME + " takes off his earmuffs.\n");
	return 1;
      }
      write("You are not wearing your earmuffs.\n");
      return 1;
    }
    if(level >= 1 && level <= TP->LEVEL) {
      if(mufflevel == 0)
	say(TP->NAME + " puts on " + TP->POS + " earmuffs.\n");
      write("You set the strength of your earmuffs to " + level + ".\n");
      worn = 1;
      TP->listen_shout(level);
      mufflevel = level;
      return 1;
    }
    write("That is not a valid level.\n");
    return 1;
  }
}

mywear(arg) {
  if(id(arg)) {
    if(!worn) {
      write("Type 'muffs <level>' to wear the earmuffs.\n");
      return 1;
    }
    write("You are already wearing the earmuffs.\n");
    return 1;
  }
}

myremove(arg) {
  if(id(arg)) {
    if(worn) {
      write("Type 'muffs 0' to remove your earmuffs.\n");
      return 1;
    }
    write("You are not wearing the earmuffs.\n");
    return 1;
  }
}

drop() {
  worn = 0;
  TP->listen_shout(0);
  mufflevel = 0;
}
