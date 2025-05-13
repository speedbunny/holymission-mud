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
      "northeast",
      "east",
      "southeast",
      "south",
      "southwest",
      "down",
    });
    alt_swim_dir=({
      "ne",
      "e",
      "se",
      "s",
      "sw",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_2",
      WKRMS+"ishikawa_sea1_6",
      WKRMS+"ishikawa_sea1_12",
      WKRMS+"ishikawa_sea1_11",
      WKRMS+"ishikawa_sea1_10",
      WKRMS+"ishikawa_sea2_1",
    });
    swim_desc="northeast, east, southeast, south, southwest or down";
    no_swim_dir=({
      "west",
      "northwest",
      "north",
    });
    alt_no_swim_dir=({
      "w",
      "nw",
      "n",
    });
    no_swim_desc="west, northwest and north";
    surface=1;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
