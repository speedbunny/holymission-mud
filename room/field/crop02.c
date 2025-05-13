inherit "/room/room";

#include <room_defs.h>
#include "fields.h"

void reset(int arg) {
  ::reset();
if(arg) return;

  set_light(1);
  short_desc="Fields";

  long_desc =
    "You are in the northern edge of the fields where " +
    "@@extra_long_north@@. The fields " +
    "extend to the south, while the road lies north. You " +
    "see the walls of a town to the west.\n";

  dest_dir = ({
    EAST + "road02", "north",
    FIELDS + "crop03", "east",
    FIELDS + "crop01", "west",
    FIELDS + "crop06", "south",
  });

  items = ({
    "crops", "@@crops_look@@",
    "flowers", "They are trampled from the traffic on the road",
    "road", "A road to the north that extends from the town west",
    "fields", "@@crops_look@@",
    "town", "It is a small town",
    "walls", "They are quite high for such a small town",
  });
}

