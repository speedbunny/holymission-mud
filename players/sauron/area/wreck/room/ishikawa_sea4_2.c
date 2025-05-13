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
    });
    alt_swim_dir=({
      "w",
      "e",
      "se",
      "s",
      "sw",
      "u",
    });
    swim_path=({
      WKRMS+"ishikawa_sea4_1",
      WKRMS+"ishikawa_sea4_3",
      WKRMS+"ishikawa_sea4_6",
      WKRMS+"ishikawa_sea4_5",
      WKRMS+"ishikawa_sea4_4",
      WKRMS+"ishikawa_sea3_3",
    });
    swim_desc="west, east, southeast, south, southwest or up";
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
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
