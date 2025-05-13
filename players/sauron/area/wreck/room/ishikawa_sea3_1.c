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
      "southeast",
      "south",
      "up",
    });
    alt_swim_dir=({
      "se",
      "s",
      "u",
    });
    swim_path=({
      WKRMS+"ishikawa_sea3_3",
      WKRMS+"ishikawa_sea3_2",
      WKRMS+"ishikawa_sea2_2",
    });
    swim_desc="southeast, south or up";
    no_swim_dir=({
      "west",
      "northwest",
      "north",
      "northeast",
      "east",
      "southwest",
    });
    alt_no_swim_dir=({
      "w",
      "nw",
      "n",
      "ne",
      "e",
      "sw",
    });
    no_swim_desc="west, northwest, north, northeast, east and southwest";
    surface=0;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
