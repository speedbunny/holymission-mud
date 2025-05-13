inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  set_light(1);

  short_desc="Intersection of East road and Shore road";

  long_desc =
    "East road intersects shore road here. East road continues "+
    "to the west and north, while Shore road travels south and "+
    "east. There are crops to the southwest.\n";

  dest_dir = ({
    EAST + "eastroad01", "north",
    EAST + "shoreroad20", "east",
    EAST + "road04", "west",
    EAST + "shoreroad01", "south",
  });

  items = ({
    "road", "There are 2 roads here: shore road and east road",
    "shore road", "The road travels to the coast",
    "east road", "The road travels to town to the west and "+
      "to the north",
    "crops", "The field is full of them",
  });

  replace_program("room/room");
}
