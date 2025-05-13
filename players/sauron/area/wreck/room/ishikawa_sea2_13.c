inherit "/players/sauron/wreck/rooms/outside_water_room";

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
      "ne",
      "e",
      "se",
      "s",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_12",
      WKRMS+"ishikawa_sea2_8",
      WKRMS+"ishikawa_sea2_9",
      WKRMS+"ishikawa_sea2_10",
      WKRMS+"ishikawa_sea2_14",
      WKRMS+"ishikawa_sea2_18",
      WKRMS+"ishikawa_sea2_17",
      WKRMS+"ishikawa_sea2_16",
      WKRMS+"ishikawa_sea1_28",
      WKRMS+"ishikawa_sea3_8",
    });
    swim_desc="west, northwest, north, northeast, east,"
             +" southeast, south, southwest, up or down";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room");
  }
}
