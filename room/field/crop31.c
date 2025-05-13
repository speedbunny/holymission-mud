inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
  if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "You are in the southwestern border of the fields where the " +
    "town wall meets the forest. @@extra_look_forest@@ Crops lie to the "+
    "northeast and there is a forest directly south.\n";

  dest_dir = ({
    FIELDS + "crop26", "north",
    FIELDS + "crop32", "east",
  });

  items = ({
    "crops", "@@crops_look@@",
    "fields", "@@crops_look@@",
    "forest", "It is thick with no way to enter",
    "town", "It is a small town",
    "walls", "They are quite high for such a small town",
  });
}

