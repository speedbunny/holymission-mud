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
      "northwest",
      "north",
      "northeast",
    });
    alt_swim_dir=({
      "nw",
      "n",
      "ne",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_38",
      WKRMS+"ishikawa_sea1_39",
      WKRMS+"ishikawa_sea1_40",
    });
    swim_desc="northwest, north or northeast";
    no_swim_dir=({
      "west",
      "east",
      "southeast",
      "south",
      "southwest",
    });
    alt_no_swim_dir=({
      "w",
      "e",
      "se",
      "s",
      "sw",
    });
    no_swim_desc="west, east, southeast, south and southwest";
    surface=1;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
