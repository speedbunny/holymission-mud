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
      "southeast",
      "south",
      "southwest",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "e",
      "se",
      "s",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_5",
      WKRMS+"ishikawa_sea2_2",
      WKRMS+"ishikawa_sea2_3",
      WKRMS+"ishikawa_sea2_7",
      WKRMS+"ishikawa_sea2_11",
      WKRMS+"ishikawa_sea2_10",
      WKRMS+"ishikawa_sea2_9",
      WKRMS+"ishikawa_sea1_13",
      WKRMS+"ishikawa_sea3_3",
    });
    swim_desc="west, northwest, north, east, southeast, south, southwest, up or down";
    alt_no_swim_dir=({
      "northeast",
    });
    no_swim_dir=({
      "ne",
    });
    no_swim_desc="northeast";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
