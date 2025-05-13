inherit "/room/room";

#include "/players/matt/defs.h"

int coins;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Voting Booth";
  long_desc =
    "    You are in a small, cramped booth. In front of you is a\n" +
    "metallic box which contains a short slot, a long slot, and\n" +
    "a lever.\n";

  dest_dir = ({
    NWCITY + "rooms/mainst03", "out",
  });

  items = ({
    "booth", "A small booth that looks like it's used for voting",
    "box", "A metallic box with a lever and two slots in it",
    "slots", "Two slots, a long one and a short one, in the box",
    "slot", "There are two slots, one long and one short",
    "short slot", "It is the size of a coin, and has 2000 written on it",
    "long slot", "A long, narrow slot in the box",
    "lever", "Made of metal, the lever extends from the box",
  });
}

init() {
  ::init();
  add_action("pull", "pull");
  add_action("put", "put");
}

pull(arg) {
  object vote;
  if(arg == "lever") {
    write("You pull the lever.\n");
    say(TP->SNAME + " pulls the lever.\n");
    if(TP->LEVEL >= 10 && (coins >= 2000)) {
      TELLR(TO, "There is a loud clanking and whirring for a moment.\n");
      TELLR(TO, "A small slip of paper pops out of the long slot.\n");
      write("You pick it up.\n");
      say(TP->SNAME + " picks it up.\n");
      vote = clone_object(NWCITY + "objects/poll");
      transfer(vote, TP);
      coins -= 2000;
      return 1;
    }
    write("Nothing further happens.\n");
    return 1;
  }
  write("Pull what?\n");
  return 1;
}

put(arg) {
  int amount;
  if(arg && (sscanf(arg, "%d coins in slot", amount)) ||
     sscanf(arg, "%d coins in short slot", amount)) {
    if(amount > 0) {
      if(TP->query_money() >= amount) {
	TP->add_money(- amount);
	coins += amount;
	write("You put " + amount + " coins in the box.\n");
	say(TP->SNAME + " puts some coins in the box.\n");
	write("There are now " + coins + " coins in the box.\n");
	return 1;
      }
      write("You don't have that much money.\n");
      return 1;
    }
    write("You must only put a positive amount into the box.\n");
    return 1;
  }
}
