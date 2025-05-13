inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Path Fork";
  long_desc =
    "    This is a path of sorts in the Western Forest. It is\n" +
    "quite dim here, but just off to the west you can see that\n" +
    "the path splits, going northwest and southwest into still\n" +
    "darker areas. You shiver, not entirely with cold.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a01", "east",
    NWFORESTA + "rooms/a04", "northwest",
    NWFORESTA + "rooms/a05", "southwest",
  });

  items = ({
    "forest", "A dark eerie forest",
    "trees", "Tall, withered trees with thick black branches",
  });
  replace_program("/room/room");
}
