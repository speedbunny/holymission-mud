inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  clone_list = ({
    1, 1, "rope", "obj/rope", 0,
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Big tree";

  long_desc =
    "A mighty tree rises out of the fertile soil of the plain.  Just beyond "+
    "the tree, a path leads further to the west.\n";

  dest_dir = ({
    PLAIN + "plain07", "east",
    PLAIN + "giant_path", "west",
  });

  items = ({
    "plain", "The plain goes east and west",
    "tree", "A very big oak",
    "big tree", "A very big oak",
    "path", "The path is large and goes from the tree westward",
  });
}

init() {
  ::init();
  add_action("_climb", "climb");
  add_action("_tie", "tie");
}

status _tie(string str) {
  switch(str) {
    case "rope to tree" :
    case "rope to the tree" :
    case "rope to big tree" :
    case "rope to the big tree" :
    case "rope to branch" :
      write("The branches are very high up.\n");
      return 1;
    case "rope" :
    case "rope to" :
      notify_fail("Tie rope to what?\n");
      return 0;
    default :
      notify_fail("Tie what?\n");
      return 0;
  }
}

status _climb(string str) {
  switch(str) {
    case "tree" :
    case "big tree" :
      write("There are no low branches.\n");
      return 1;
    default :
      notify_fail("Climb what?\n");
      return 0;
  }
}
