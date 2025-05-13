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
      "south",
      "southwest",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "s",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea3_3",
      WKRMS+"ishikawa_sea3_7",
      WKRMS+"ishikawa_sea3_6",
      WKRMS+"ishikawa_sea2_7",
      WKRMS+"ishikawa_sea4_3",
    });
    swim_desc="west, south, southwest, up or down";
    no_swim_dir=({
      "northwest",
      "north",
      "northeast",
      "east",
      "southeast",
    });
    alt_no_swim_dir=({
      "nw",
      "n",
      "ne",
      "e",
      "se",
    });
    no_swim_desc="northwest, north, northeast, east and southeast";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
