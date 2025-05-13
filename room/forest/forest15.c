inherit "room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "In a forest";

  long_desc =
    "You are in a big forest. There are large "+
    "deformed footprints leading off south.\n";

  items = ({
    "forest","It is big and smells quite nice",
    "footprints","You look them over and decide that they could have "+
      "been made by a troll",
  });

  dest_dir = ({
    FOREST + "forest14", "east",
    FOREST + "forest16", "west",
    "/players/kryll/rooms/trollslayer/forest01", "south",
  });

  smell = "You smell the fresh air of the forest.";

  ::reset();
  replace_program("room/room");
}
