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
      "southwest",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "ne",
      "e",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea3_8",
      WKRMS+"ishikawa_sea3_5",
      WKRMS+"ishikawa_sea3_6",
      WKRMS+"ishikawa_sea3_7",
      WKRMS+"ishikawa_sea3_10",
      WKRMS+"ishikawa_sea3_11",
      WKRMS+"ishikawa_sea2_14",
      WKRMS+"ishikawa_sea4_8",
    });
    swim_desc="west, northwest, north, northeast, east, south, up or down";
    no_swim_dir=({
      "southeast",
      "south",
    });
    alt_no_swim_dir=({
      "se",
      "s",
    });
    no_swim_desc="southeast and south";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
