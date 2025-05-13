inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
  if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "You are in the northeastern edge of the fields where " +
    "@@extra_long_north@@. The fields " +
    "extend to the south, while a road lies north and east. You " +
    "see the walls of a town far to the west.\n";

  dest_dir = ({
    EAST + "road04", "north",
    EAST + "shoreroad01", "east",
    FIELDS + "crop03", "west",
    FIELDS + "crop08", "south",
  });

  items = ({
    "crops", "@@crops_look@@",
    "flowers", "They are trampled from the traffic on the road",
    "road", "There is a road to the north that extends from the "+
      "town west and one to the east that runs north-south",
    "fields", "@@crops_look@@",
    "town", "It is a small town",
    "walls", "They are quite high for such a small town",
  });
}

