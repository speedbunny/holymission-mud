inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
  if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "In the middle of the field, the crops glisten in the "+
    "sunlight. @@extra_look_center@@ There are walls to a town "+
    "to the west and a forest to the south.\n";

  dest_dir = ({
    FIELDS + "crop17", "north",
    FIELDS + "crop23", "east",
    FIELDS + "crop21", "west",
    FIELDS + "crop27", "south",
  });

  items = ({
    "crops", "@@crops_look@@",
    "fields", "@@crops_look@@",
    "field", "@@crops_look@@",
    "town", "It is a small town",
    "walls", "They are quite high for such a small town",
    "forest", "The forest is thick",
  });
}

