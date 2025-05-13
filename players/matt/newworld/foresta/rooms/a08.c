inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Misty Area";
  long_desc =
    "    You stand knee-high in a cold white mist that hugs the\n" +
    "ground here. Your feet feel like they are slowly numbing from\n" +
    "the cold, which seems to cling to them with a life of its\n" +
    "own. Though the trees are somewhat thick here, you can see an\n" +
    "opening to the north, entirely filled with the mist.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a03", "southeast",
  });

  items = ({
    "mist", "Cold white mist clinging to your body",
    "ground", "You cannot see the ground, it is covered with mist",
    "trees", "They look hazy",
    "opening", "A curtain of mist covers the opening to the north",
  });
}
     
init() {
  ::init();
  add_action("enter", "enter");
  add_action("mist", "north");
}

enter(arg) {
  if(arg == "mist" || arg == "opening" || arg == "curtain") {
    mist();
    return 1;
  }
  write("Enter what?\n");
  return 1;
}

mist() {
  write("You plunge through the misty curtain.\n");
  TP->MOVEP("through the misty curtain#" + NWFORESTA + "rooms/a07");
  return 1;
}
