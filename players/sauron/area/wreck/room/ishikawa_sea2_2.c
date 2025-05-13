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
      "east",
      "southeast",
      "south",
      "southwest",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "e",
      "se",
      "s",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea2_1",
      WKRMS+"ishikawa_sea2_3",
      WKRMS+"ishikawa_sea2_6",
      WKRMS+"ishikawa_sea2_5",
      WKRMS+"ishikawa_sea2_4",
      WKRMS+"ishikawa_sea1_6",
      WKRMS+"ishikawa_sea3_1",
    });
    swim_desc="west, east, southeast, south, southwest, up or down";
    no_swim_dir=({
      "northwest",
      "north",
      "northeast",
    });
    alt_no_swim_dir=({
      "nw",
      "n",
      "ne",
    });
    no_swim_desc="northwest, north and northeast";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
