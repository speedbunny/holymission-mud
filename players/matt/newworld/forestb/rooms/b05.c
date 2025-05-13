inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mud Hole";
  long_desc =
    "    You stand in a mud hole, knee-deep in wet brown muck.\n" +
    "It is very difficult to move freely, as the mud seems to\n" +
    "pull you down every time you try. There is a certain gloom\n" +
    "over this place, a pall of sadness that you cannot ignore.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b09", "southeast",
  });

  items = ({
    "mud", "A deep layer of brownish mud",
    "hole", "The entire area is covered with mud and sludge",
  });
  replace_program("/room/room");
}
