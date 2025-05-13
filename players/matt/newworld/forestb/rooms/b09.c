inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Muddy Area";
  long_desc =
    "    The ground here is more like a swamp than a forest floor.\n" +
    "You have sunk up to your ankles into a thick layer of mud and\n" +
    "sludgy water, and find it difficult to keep your footing. The\n" +
    "ground seems a bit more dry to the south, but seems to get\n" +
    "more muddy to the northwest.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b10", "south",
    NWFORESTB + "rooms/b05", "northwest",
  });

  items = ({
    "ground", "Murky, muddy earth",
    "mud", "Thick brown mud covering the forest floor",
    "water", "Dark brown water in muddy puddles",
    "floor", "The forest floor is marred with spots of deep mud",
  });
  replace_program("/room/room");
}
