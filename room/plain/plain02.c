inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "You are in a large bare open plain, extending as " +
    "far as the eye can see in all directions. A few " +
    "birds fly overhead - you can sometimes hear their cries.  For some "+
    "inexplicable reason, a castle seems to be floating in the sky.\n";

  dest_dir = ({
    PLAIN + "plain03", "north",
    PLAIN + "plain04", "east",
    PLAIN + "plain05", "west",
    PLAIN + "plain01", "south",
    "/players/emerald/good/evil/enterhall","jump",
  });

  items = ({
    "birds", "They look like vultures, searching for prey",
    "plain","A vast desolate plain",
    "castle","A large castle floating in the middle of the sky.  If you "+
             "jump really hard, you might be able to make it to the entrance",
  });

  ::reset(arg);
  replace_program("room/room");
}

