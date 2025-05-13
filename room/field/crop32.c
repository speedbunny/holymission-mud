inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
  if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "You are in the southwest corner of the fields where the "+
    "forest meets the town wall. @@extra_look_forest@@ "+
    "Crops lie further to the north and the forest blocks travel "+
    "to the south.\n";

  dest_dir = ({
    FIELDS + "crop27", "north",
    FIELDS + "crop31", "west",
  });

  items = ({
    "crops", "@@crops_look@@",
    "fields", "@@crops_look@@",
    "forest", "It is too thick to enter",
    "town", "It is a small town",
    "walls", "They are quite high for such a small town",
  });
}

