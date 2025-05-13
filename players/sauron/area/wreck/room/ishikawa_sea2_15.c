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
      "southwest",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_14",
      WKRMS+"ishikawa_sea2_10",
      WKRMS+"ishikawa_sea2_11",
      WKRMS+"ishikawa_sea2_18",
      WKRMS+"ishikawa_sea1_30",
      WKRMS+"ishikawa_sea3_10",
    });
    swim_desc="west, northwest, north, southwest, up or down";
    no_swim_dir=({
      "northeast",
      "east",
      "southeast",
      "south",
    });
    alt_no_swim_dir=({
      "ne",
      "e",
      "se",
      "s",
    });
    no_swim_desc="northeast, east, south and southeast";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
