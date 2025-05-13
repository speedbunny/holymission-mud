inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Turn";
  long_desc =
    "    Here the road turns, leading northwest into hilly country\n" +
    "and directly south into the grasslands. Plains stretch widely\n" +
    "on either side of the path, and a slight wind stirs the grass.\n" +
    "The mountains loom rather menacingly to the north.\n";

  dest_dir = ({
    NWROAD + "rooms/road09", "northwest",
    NWROAD + "rooms/road07", "south",
    NWPLAINS + "rooms/plain05", "east",
    NWPLAINS + "rooms/plain06", "west",
  });

  items = ({
    "plains", "Large grassy plains",
    "road", "This is North Road",
    "mountains", "The mountains dwarf everything around them",
  });
  replace_program("/room/room");
}
