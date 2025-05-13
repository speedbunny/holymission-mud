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
      "north",
      "northeast",
      "east",
      "southeast",
      "south",
      "up",
    });
    alt_swim_dir=({
      "n",
      "ne",
      "e",
      "se",
      "s",
      "u",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_8",
      WKRMS+"ishikawa_sea2_9",
      WKRMS+"ishikawa_sea2_13",
      WKRMS+"ishikawa_sea2_17",
      WKRMS+"ishikawa_sea2_16",
      WKRMS+"ishikawa_sea1_27",
    });
    swim_desc="north, northeast, east, southeast, south or up";
    no_swim_dir=({
      "west",
      "northwest",
      "southwest",
    });
    alt_no_swim_dir=({
      "w",
      "nw",
      "sw",
    });
    no_swim_desc="west, northwest and southwest";
    surface=0;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
