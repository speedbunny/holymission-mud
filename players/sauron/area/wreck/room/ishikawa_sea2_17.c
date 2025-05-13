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
      "northeast",
      "east",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "ne",
      "e",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_16",
      WKRMS+"ishikawa_sea2_12",
      WKRMS+"ishikawa_sea2_13",
      WKRMS+"ishikawa_sea2_14",
      WKRMS+"ishikawa_sea2_18",
      WKRMS+"ishikawa_sea1_34",
      WKRMS+"ishikawa_sea3_11",
    });
    swim_desc="west, northwest, north, northeast, east, up or down";
    no_swim_dir=({
      "southeast",
      "south",
      "southwest",
    });
    alt_no_swim_dir=({
      "se",
      "s",
      "sw",
    });
    no_swim_desc="southeast, south and southwest";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
