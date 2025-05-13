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
      "east",
      "south",
      "southwest",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "e",
      "s",
      "sw",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_23",
      WKRMS+"ishikawa_sea1_15",
      WKRMS+"ishikawa_sea1_16",
      WKRMS+"ishikawa_sea1_25",
      WKRMS+"ishikawa_sea1_32",
      WKRMS+"ishikawa_sea1_31",
    });
    swim_desc="west, northwest, north, east, south or southwest";
    no_swim_dir=({
      "northeast",
      "southeast",
      "down",
    });
    alt_no_swim_dir=({
      "ne",
      "se",
      "d",
    });
    no_swim_desc="northeast, southeast and below you";
    surface=1;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
