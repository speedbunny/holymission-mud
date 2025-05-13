inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="Shore road";

  long_desc =
    "Shore road runs north-south here and passes some crops "+
    "to the west.\n";

  dest_dir = ({
    EAST + "shoreroad01", "north",
    FIELDS + "crop08", "west",
    EAST + "shoreroad03", "south",
  });

  items = ({
    "road", "The road continues both north and south",
    "crops", "The field is full of them",
  });

  replace_program("room/room");
}
