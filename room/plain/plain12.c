inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "Here, the plains are bordered by a large " +
    "mountain to the north, which looms up over " +
    "you, cutting off the sunshine. It could be " +
    "your eyes playing tricks on you, but there "+
    "could be a cave at the base of the hills to "+
    "the west.\n";

  dest_dir = ({
    PLAIN + "plain11", "east",
    PLAIN + "open_cave", "west",
    PLAIN + "plain10", "south",
  });

  items = ({
    "mountain", "A large mountain rears up above you. " +
      "It is far too steep to climb",
    "cave", "Just go west into it",
    "plains", "They widen to the south",
    "hills", "There are hills to the west as they grow bigger "+
      "forming mountains",
  });

  ::reset(arg);
  replace_program("room/room");
}

