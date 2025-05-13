inherit "/room/room";

#include "/players/matt/defs.h"

object knife;

reset(arg) {
  if(!knife) knife = clone_object(NWFORESTB + "objects/blknife");
  if(arg) return;
  set_light(0);
  short_desc = "Small Crack";
  long_desc =
    "    You are huddled inside a small opening in the blasted tree.\n" +
    "It is very cramped and dark, and you begin to feel somewhat\n" +
    "claustrophobic as you look about and see the inside surface of\n" +
    "the tree mere inches from your face.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b14", "out",
  });

  items = ({
    "surface", "The wooden inner surface of the tree you stand within",
    "crack", "The narrow crack through which you entered",
    "opening", "A narrow opening in the tree",
    "tree", "The blasted remains of an ancient tree",
  });
}

init() {
  ::init();
  add_action("search", "search");
}

search(arg) {
  if(!arg || arg == "crack" || arg == "narrow crack" ||
     arg == "tree") {
    if(set_light(0)) {
      if(knife) {
	write("You search around and cut your hand on something sharp.\n");
	say(TP->NAME + " searches around and suddenly cries out in pain.\n");
	TP->ADDHP(-10);
	MOVE(knife, TO);
        knife = 0;
	return 1;
      }
      write("You search around but find nothing special.\n");
      return 1;
    }
    write("It is too dark.\n");
    return 1;
  }
  write("Search what?\n");
  return 1;
}

