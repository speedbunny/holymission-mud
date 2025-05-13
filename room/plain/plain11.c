inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "A large open plain";

  long_desc =
    "This is a huge, bare, windswept open plain, " +
    "overshadowed by massive mountains which " +
    "rise up above you to the north.\n";

  dest_dir = ({
    PLAIN + "mount_pass", "north",
    PLAIN + "plain13", "east",
    PLAIN + "plain12", "west",
    PLAIN + "plain06", "south",
  });

  items = ({
    "mountains", "They really are immensely large mountains",
    "plain", "The plain is to the south",
  });

  ::reset(arg);
  replace_program("room/room");
}

