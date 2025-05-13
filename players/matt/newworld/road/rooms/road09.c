inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "North Road";
  long_desc =
    "    The road slopes here, rising upward towards the mountains\n" +
    "to the north and sinking downward towards the southern plains.\n" +
    "The land around the path is very steep and rocky. You can see\n" +
    "a fork in the road to the northwest.\n" +
    "    Faint wisps of smoke rise into the air to the west.\n";

  dest_dir = ({
    NWROAD + "rooms/road10", "northwest",
    NWROAD + "rooms/road08", "southeast",
  });

  items = ({
    "plains", "Grassy plains to your south",
    "road", "This is North Road",
    "mountains", "The mountains are rather close now",
    "smoke", "It looks as though the smoke comes from a city",
    "wisps", "Wisps of light smoke",
  });
  replace_program("/room/room");
}
