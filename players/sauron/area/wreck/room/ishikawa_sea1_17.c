inherit "/players/sauron/wreck/rooms/outside_water_room2";

#include "/players/sauron/std_defs.h"
#include "/players/sauron/wreck/path_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="In the sea off Ishikawa.";
    long_desc="You are swimming in the sea off the east coast"
             +" of Ishikawa. The water here is shallow and warm,"
             +" and you can touch the bottom if you dive down a"
             +" few feet. To the west you can see the Island of"
             +" Ishikawa stretched out to the north and south"
             +" along the horizon.\n";
    swim_dir=({
      "northeast",
      "east",
      "southeast",
    });
    alt_swim_dir=({
      "ne",
      "e",
      "se",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_10",
      WKRMS+"ishikawa_sea1_18",
      WKRMS+"ishikawa_sea1_26",
    });
    swim_desc="northeast, east or southeast";
    no_swim_dir=({
      "west",
      "northwest",
      "north",
      "south",
      "southwest",
    });
    alt_no_swim_dir=({
      "w",
      "nw",
      "n",
      "s",
      "sw",
    });
    no_swim_desc="west, northwest, north, south and southwest";
    surface=1;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
