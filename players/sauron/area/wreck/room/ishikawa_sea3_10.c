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
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea3_9",
      WKRMS+"ishikawa_sea3_6",
      WKRMS+"ishikawa_sea3_7",
      WKRMS+"ishikawa_sea2_15",
      WKRMS+"ishikawa_sea4_9",
    });
    swim_desc="west, northwest, north, up or down";
    no_swim_dir=({
      "northeast",
      "east",
      "southeast",
      "south",
      "southwest",
    });
    alt_no_swim_dir=({
      "ne",
      "e",
      "se",
      "s",
      "sw",
    });
    no_swim_desc="northeast, east, southeast, south and southwest";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
