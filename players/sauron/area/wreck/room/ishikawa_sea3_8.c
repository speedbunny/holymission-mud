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
      "north",
      "northeast",
      "east",
      "south",
      "up",
      "down",
    });
    alt_swim_dir=({
      "n",
      "ne",
      "e",
      "s",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea3_5",
      WKRMS+"ishikawa_sea3_6",
      WKRMS+"ishikawa_sea3_9",
      WKRMS+"ishikawa_sea3_11",
      WKRMS+"ishikawa_sea2_13",
      WKRMS+"ishikawa_sea4_7",
    });
    swim_desc="north, northeast, east, south, up or down";
    no_swim_dir=({
      "west",
      "northwest",
      "southeast",
      "southwest",
    });
    alt_no_swim_dir=({
      "w",
      "nw",
      "se",
      "sw",
    });
    no_swim_desc="west, northwest, southeast and southwest";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
