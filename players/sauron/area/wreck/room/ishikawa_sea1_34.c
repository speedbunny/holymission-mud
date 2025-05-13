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
      "east",
      "southeast",
      "south",
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
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_33",
      WKRMS+"ishikawa_sea1_27",
      WKRMS+"ishikawa_sea1_28",
      WKRMS+"ishikawa_sea1_29",
      WKRMS+"ishikawa_sea1_35",
      WKRMS+"ishikawa_sea1_39",
      WKRMS+"ishikawa_sea1_38",
      WKRMS+"ishikawa_sea2_17",
    });
    swim_desc="west, northwest, north, northeast, east, southeast, south or down";
    no_swim_dir=({
      "southwest",
    });
    alt_no_swim_dir=({
      "sw",
    });
    no_swim_desc="southwest";
    surface=1;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
