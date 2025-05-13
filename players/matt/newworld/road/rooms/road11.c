inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "City Road";
  long_desc =
    "    This road leads to Dyolf City. It looks very worn and well-\n" +
    "traveled, and you can see hundreds of footprints, hoofprints,\n" +
    "and cartwheel tracks going northwest and east in the dust along\n" +
    "the road. You can faintly hear the busy sounds of the city in\n" +
    "the distance.\n";

  dest_dir = ({
    NWROAD + "rooms/road12", "northwest",
    NWROAD + "rooms/road10", "east",
  });

  items = ({
    "footprints", "Footprints going in both directions",
    "road", "This is a well-used path into the city",
    "hoofprints", "It looks as though these were made by a horse",
    "tracks", "Long tracks made by carts and wagons",
    "dust", "The dust in the road is marked with many tracks",
  });
  replace_program("/room/room");
}
