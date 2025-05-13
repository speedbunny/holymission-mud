inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
  if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "The crops border a thick forest here, which prevents further "+
    "travel to the south. @@extra_look_forest@@ As you look at the "+
    "forest, you see that small patches of mushrooms have sprouted. "+
    "There is a town wall to the west.\n";

  dest_dir = ({
    FIELDS + "crop15", "north",
    FIELDS + "crop19", "west",
    FIELDS + "crop25", "south",
  });

  items = ({
    "crops", "@@crops_look@@",
    "fields", "@@crops_look@@",
    "forest", "It is too thick to enter",
    "mushrooms", "They are just sprouting",
    "patches", "A group of mushrooms",
    "town", "It is a small town",
    "wall", "It is quite high for such a small town",
  });
}

