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
      "south",
      "southwest",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "s",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_6",
      WKRMS+"ishikawa_sea2_3",
      WKRMS+"ishikawa_sea2_11",
      WKRMS+"ishikawa_sea2_10",
      WKRMS+"ishikawa_sea1_14",
      WKRMS+"ishikawa_sea3_4",
    });
    swim_desc="west, northwest, south, southwest, up or down";
    no_swim_dir=({
      "north",
      "northeast",
      "east",
      "southeast",
    });
    alt_no_swim_dir=({
      "n",
      "ne",
      "e",
      "se",
    });
    no_swim_desc="north, northeast, east and southeast";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
