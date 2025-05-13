inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Castle Road";
  long_desc =
    "    This is a north-south section of North Road, leading\n" +
    "north towards the castle and south down the mountainside.\n" +
    "You can see a smaller structure between you and the castle\n" +
    "which marks the end of this road.\n";

  dest_dir = ({
    NWCASTLE + "rooms/outside", "north",
    NWROAD + "rooms/road23", "south",
  });
  
  items = ({
    "road", "The road ends to the north",
    "castle", "You are fairly close to the castle",
    "mountainside", "This is the path you climbed to get here",
    "structure", "It looks like a gatehouse",
    "gatehouse", "A black gatehouse made of solid stone",
  });
  replace_program("/room/room");
}
