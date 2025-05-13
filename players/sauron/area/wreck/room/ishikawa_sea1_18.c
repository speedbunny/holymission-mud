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
      "northeast",
      "east",
      "southeast",
      "south",
    });
    alt_swim_dir=({
      "w",
      "n",
      "ne",
      "e",
      "se",
      "s",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_17",
      WKRMS+"ishikawa_sea1_10",
      WKRMS+"ishikawa_sea1_11",
      WKRMS+"ishikawa_sea1_19",
      WKRMS+"ishikawa_sea1_27",
      WKRMS+"ishikawa_sea1_26",
    });
    swim_desc="west, north, northeast, east, southeast or south";
    no_swim_dir=({
      "northwest",
      "southwest",
    });
    no_swim_dir=({
      "nw",
      "sw",
    });
    no_swim_desc="northwest and southwest";
    surface=1;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
