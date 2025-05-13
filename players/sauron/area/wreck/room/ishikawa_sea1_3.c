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
      "north",
      "east",
      "southeast",
      "south",
      "southwest",
    });
    alt_swim_dir=({
      "w",
      "n",
      "e",
      "se",
      "s",
      "sw",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_2",
      WKRMS+"ishikawa_sea1_1",
      WKRMS+"ishikawa_sea1_4",
      WKRMS+"ishikawa_sea1_8",
      WKRMS+"ishikawa_sea1_7",
      WKRMS+"ishikawa_sea1_6",
    });
    swim_desc="west, north, east, southeast, south or southwest";
    no_swim_dir=({
      "northwest",
      "northeast",
    });
    alt_no_swim_dir=({
      "nw",
      "ne",
    });
    no_swim_desc="northwest and northeast";
    surface=1;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
