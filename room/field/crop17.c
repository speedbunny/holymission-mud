inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
  if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "You are in the western border of the fields where the " +
    "town wall lies. @@extra_look_west@@ Crops lie to the "+
    "east and there is a forest to the south.\n";

  dest_dir = ({
    FIELDS + "crop18", "east",
    FIELDS + "crop22", "south",
  });

  items = ({
    "crops", "@@crops_look@@",
    "fields", "@@crops_look@@",
    "forest", "It is thick",
    "town", "It is a small town",
    "walls", "They are quite high for such a small town",
  });
}

