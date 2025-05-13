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
      "southwest",
      "down",
    });
    alt_swim_dir=({
      "w",
      "n",
      "ne",
      "e",
      "se",
      "s",
      "sw",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_10",
      WKRMS+"ishikawa_sea1_5",
      WKRMS+"ishikawa_sea1_6",
      WKRMS+"ishikawa_sea1_12",
      WKRMS+"ishikawa_sea1_20",
      WKRMS+"ishikawa_sea1_19",
      WKRMS+"ishikawa_sea1_18",
      WKRMS+"ishikawa_sea2_4",
    });
    swim_desc="west, north, northeast, east, southeast, south, southwest or down";
    no_swim_dir=({
      "northwest",
    });
    alt_no_swim_dir=({
      "nw",
    });
    no_swim_desc="northwest";
    surface=1;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
