inherit "/room/room";

#include "/players/matt/defs.h"

object board;

reset(arg) {
  if(!board) {
    board = clone_object(NEWWORLD + "mainboard");
    MOVE(board, TO);
  }
  if(arg) return;
  set_light(1);
  short_desc = "New World";
  long_desc =
    "    You are standing outside in a New World. The sky above is\n" +
    "clear and deep blue, and the sun is shining brightly. A gentle\n" +
    "breeze blows through, causing the branches of the surrounding\n" +
    "trees to sway a bit. The main road begins here, leading north\n" +
    "towards the mountains, and there is a dense forest to the west\n" +
    "and the east.\n" +
    "    The black Archway stands south of you.\n";

  dest_dir = ({
    NWROAD + "rooms/road01", "north",
  });

  items = ({
    "sky", "Wispy white clouds drift lazily across the blue sky",
    "sun", "DAMN! You just really messed up your eyes",
    "branches", "The branches sway gently in the wind",
    "trees", "The trees are large and packed tightly together",
    "road", "North Road is made of hard-packed earth",  
    "mountains", "Huge peaks reaching towards the sky",
    "forest", "The dense forest is on either side of you",
    "archway", "This is the Archway through which you entered"
    });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "east");
  add_action("enter", "enter");
}
        
no_way() {
  write("The forest is too thick here.\n");
  return 1;
}

enter(arg) {
  if(arg == "gate" || arg == "arch" || arg == "archway") {
    write("You enter the Gate.\n");
    TP->MOVEP("through the Gate and vanishes#" +
              "/players/haplo/ravine/clifftop");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
