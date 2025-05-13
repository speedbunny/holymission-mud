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
      "northeast",
      "up",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "n",
      "ne",
      "u",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_17",
      WKRMS+"ishikawa_sea2_13",
      WKRMS+"ishikawa_sea2_14",
      WKRMS+"ishikawa_sea2_15",
      WKRMS+"ishikawa_sea1_35",
    });
    swim_desc="west, northwest, north, northeast or up";
    no_swim_dir=({
      "east",
      "southeast",
      "south",
      "southwest",
    });
    alt_no_swim_dir=({
      "e",
      "se",
      "s",
      "sw",
    });
    no_swim_desc="east, southeast, south and southwest";
    surface=0;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
