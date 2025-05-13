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
      "southeast",
      "south",
      "southwest",
      "up",
    });
    alt_swim_dir=({
      "w",
      "se",
      "s",
      "sw",
      "u",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_2",
      WKRMS+"ishikawa_sea2_7",
      WKRMS+"ishikawa_sea2_6",
      WKRMS+"ishikawa_sea2_5",
      WKRMS+"ishikawa_sea1_7",
    });
    swim_desc="west, southeast, south, southwest or up";
    no_swim_dir=({
      "northwest",
      "north",
      "northeast",
      "east",
    });
    alt_no_swim_dir=({
      "nw",
      "n",
      "ne",
      "e",
    });
    no_swim_desc="northwest, north, northeast and east";
    surface=0;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
