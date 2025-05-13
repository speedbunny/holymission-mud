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
      "east",
      "southeast",
      "down",
    });
    alt_swim_dir=({
      "nw",
      "n",
      "ne",
      "e",
      "se",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_26",
      WKRMS+"ishikawa_sea1_27",
      WKRMS+"ishikawa_sea1_28",
      WKRMS+"ishikawa_sea1_34",
      WKRMS+"ishikawa_sea1_38",
      WKRMS+"ishikawa_sea2_16",
    });
    swim_desc="northwest, north, northeast, east, southeast or down";
    no_swim_dir=({
      "west",
      "south",
      "southwest",
    });
    alt_no_swim_dir=({
      "w",
      "s",
      "sw",
    });
    no_swim_desc="west, south, southwest";
    surface=1;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
