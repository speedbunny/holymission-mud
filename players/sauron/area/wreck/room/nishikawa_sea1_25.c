inherit "/players/sauron/wreck/rooms/noutside_water_room2";

#include "/players/sauron/std_defs.h"
#include "/players/sauron/wreck/path_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="In the sea off Ishikawa.";
    set_long("You are swimming in the sea off the east coast"
            +" of Ishikawa.\n");
    add_swim_exit("west",      "w", WKRMS+"ishikawa_sea1_24");
    add_swim_exit("northwest", "nw",WKRMS+"ishikawa_sea1_16");
    add_swim_exit("southwest", "sw",WKRMS+"ishikawa_sea1_32");
    set_swim_desc("west, northwest or southwest");

    cold_swim_exit("north",    "n");
    cold_swim_exit("northeast","ne");
    cold_swim_exit("east",     "e");
    cold_swim_exit("southeast","se");
    cold_swim_exit("south",    "s");
    cold_swim_exit("down",     "d");
    set_cold_swim_desc("north, northeast, east, southeast, south"
                      +" and below you");
    set_surface();
    items=({
    });
    RP("/players/sauron/wreck/rooms/noutside_water_room2");
  }
}
