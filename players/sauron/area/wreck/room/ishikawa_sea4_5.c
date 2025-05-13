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
      "up",
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
      "u",
    });
    swim_path=({
      WKRMS+"ishikawa_sea4_4",
      WKRMS+"ishikawa_sea4_1",
      WKRMS+"ishikawa_sea4_2",
      WKRMS+"ishikawa_sea4_3",
      WKRMS+"ishikawa_sea4_6",
      WKRMS+"ishikawa_sea4_9",
      WKRMS+"ishikawa_sea4_8",
      WKRMS+"ishikawa_sea4_7",
      WKRMS+"ishikawa_sea3_6",
    });
    swim_desc="west, northwest, north, northeast, east,"
             +" southeast, south, southwest or up";
    surface=0;
    sea_floor=1;
    items=({
    });
    RP("/players/sauron/wreck/rooms/outside_water_room");
  }
}
