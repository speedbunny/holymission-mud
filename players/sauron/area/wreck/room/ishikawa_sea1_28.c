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
      WKRMS+"ishikawa_sea1_27",
      WKRMS+"ishikawa_sea1_19",
      WKRMS+"ishikawa_sea1_20",
      WKRMS+"ishikawa_sea1_21",
      WKRMS+"ishikawa_sea1_29",
      WKRMS+"ishikawa_sea1_35",
      WKRMS+"ishikawa_sea1_34",
      WKRMS+"ishikawa_sea1_33",
      WKRMS+"ishikawa_sea2_13",
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
