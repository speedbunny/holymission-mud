inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="Shore road";

  long_desc =
    "Shore road runs north-southeast here and passes some crops "+
    "to the west and a forest to the south.\n";

  dest_dir = ({
    EAST + "shoreroad03", "north",
    FIELDS + "crop16", "west",
    EAST + "shoreroad05", "southeast",
  });

  items = ({
    "road", "The road continues both north and southeast",
    "crops", "The field is full of them",
    "forest", "It is too thick to enter",
  });

  replace_program("room/room");
}
