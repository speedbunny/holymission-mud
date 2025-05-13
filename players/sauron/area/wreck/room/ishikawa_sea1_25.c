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
      "southwest",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "sw",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_24",
      WKRMS+"ishikawa_sea1_16",
      WKRMS+"ishikawa_sea1_32",
    });
    swim_desc="west, northwest or southwest";
    no_swim_dir=({
      "north",
      "northeast",
      "east",
      "southeast",
      "south",
      "down",
    });
    alt_no_swim_dir=({
      "n",
      "ne",
      "e",
      "se",
      "s",
      "d",
    });
    no_swim_desc="north, northeast, east, southeast, south and below you";
    surface=1;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
