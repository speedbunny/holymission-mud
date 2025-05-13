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
      "east",
      "southeast",
      "south",
      "southwest",
      "up",
      "down",
    });
    alt_swim_dir=({
      "w",
      "nw",
      "e",
      "se",
      "s",
      "sw",
      "u",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea3_2",
      WKRMS+"ishikawa_sea3_1",
      WKRMS+"ishikawa_sea3_4",
      WKRMS+"ishikawa_sea3_7",
      WKRMS+"ishikawa_sea3_6",
      WKRMS+"ishikawa_sea3_5",
      WKRMS+"ishikawa_sea2_6",
      WKRMS+"ishikawa_sea4_2",
    });
    swim_desc="west, northwest, east, southeast, south, southwest, up or down";
    no_swim_dir=({
      "north",
      "northeast",
    });
    alt_no_swim_dir=({
      "n",
      "ne",
    });
    no_swim_desc="north or northeast";
    surface=0;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room2");
  }
}
