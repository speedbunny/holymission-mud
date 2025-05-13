inherit "/players/sauron/wreck/rooms/outside_water_room2";

#include "/players/sauron/std_defs.h"
#include "/players/sauron/wreck/path_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="In the sea.";
    long_desc="You are swimming in the sea off the east coast"
             +" of Ishikawa.\n";
    swim_dir=({
      "west",
      "northwest",
      "north",
      "south",
      "southwest",
      "up",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "s",
      "sw",
      "u",
    });
    swim_path=({
      WKRMS+"ishikawa_sea4_5",
      WKRMS+"ishikawa_sea4_2",
      WKRMS+"ishikawa_sea4_3",
      WKRMS+"ishikawa_sea4_9",
      WKRMS+"ishikawa_sea4_8",
      WKRMS+"ishikawa_sea3_7",
    });
    swim_desc="west, northwest, north, south, southwest or up";
    no_swim_dir=({
      "northeast",
      "east",
      "southeast",
    });
    alt_no_swim_dir=({
      "ne",
      "e",
      "se",
    });
    no_swim_desc="northeast, east and southeast";
    surface=0;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
