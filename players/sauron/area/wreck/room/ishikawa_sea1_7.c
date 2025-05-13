inherit "/players/sauron/wreck/rooms/outside_water_room";

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
      "southwest",
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
      "sw",
      "d",
    });
    swim_path=({
      WKRMS+"ishikawa_sea1_6",
      WKRMS+"ishikawa_sea1_2",
      WKRMS+"ishikawa_sea1_3",
      WKRMS+"ishikawa_sea1_4",
      WKRMS+"ishikawa_sea1_8",
      WKRMS+"ishikawa_sea1_14",
      WKRMS+"ishikawa_sea1_13",
      WKRMS+"ishikawa_sea1_12",
      WKRMS+"ishikawa_sea2_3",
    });
    swim_desc="west, northwest, north, northeast, east,"
             +" southeast, south, southwest or down";
    surface=1;
    sea_floor=0;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room");
  }
}
