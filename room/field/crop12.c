inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
  if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "You have walked into the eastern side of the fields "+
    "nearest the road. You notice fresh tracks and "+
    "@@extra_look_east@@ There are walls to a town far "+
    "to the west.\n";

  dest_dir = ({
    FIELDS + "crop08", "north",
    EAST + "shoreroad03", "east",
    FIELDS + "crop11", "west",
    FIELDS + "crop16", "south",
  });

  items = ({
    "crops", "@@crops_look@@",
    "flowers", "They are trampled from the traffic on the road",
    "road", "There is a road to the east that runs north-south",
    "fields", "@@crops_look@@",
    "town", "It is a small town",
    "walls", "They are quite high for such a small town",
  });
}

