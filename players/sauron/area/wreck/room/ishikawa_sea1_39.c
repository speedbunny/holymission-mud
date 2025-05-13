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
      "south",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "ne",
      "e",
      "s",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_38",
      WKRMS+"ishikawa_sea1_34",
      WKRMS+"ishikawa_sea1_35",
      WKRMS+"ishikawa_sea1_36",
      WKRMS+"ishikawa_sea1_40",
      WKRMS+"ishikawa_sea1_41",
    });
    swim_desc="west, northwest, north, northeast, east or south";
    no_swim_dir=({
      "southeast",
      "southwest",
    });
    alt_no_swim_dir=({
      "se",
      "sw",
    });
    no_swim_desc="southeast and southwest";
    surface=1;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
