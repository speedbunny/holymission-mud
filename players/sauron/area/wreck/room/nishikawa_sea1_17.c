inherit "/players/sauron/wreck/rooms/noutside_water_room";

#include "/players/sauron/std_defs.h"
#include "/players/sauron/wreck/path_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="In the sea off Ishikawa.";
    set_long("You are swimming in the sea off the east coast"
            +" of Ishikawa. The water here is shallow and warm,"
            +" and you can touch the bottom if you dive down a"
            +" few feet. To the west you can see the Island of"
            +" Ishikawa stretched out to the north and south"
            +" along the horizon.\n");
    add_swim_exit("northeast","ne",WKRMS+"ishikawa_sea1_10");
    add_swim_exit("east",     "e", WKRMS+"ishikawa_sea1_18");
    add_swim_exit("southeast","se",WKRMS+"ishikawa_sea1_26");
    set_swim_desc("northeast, east or southeast");
    set_surface();
    set_sea_floor();
    items=({
      "coast","You can see the shore of the island of Ishikawa"
             +" stretched out north-south along the horizon to"
             +" the west",
      "ishikawa","You can see the shore of the island of Ishikawa"
                +" stretched out north-south along the horizon to"
                +" the west",
      "island","You can see the shore of the island of Ishikawa"
              +" stretched out north-south along the horizon to"
              +" the west",
      "horizon","You can see the shore of the island of Ishikawa"
               +" stretched out north-south along the horizon to"
               +" the west",
      "bottom","You can see the sea floor just below your feet."
              +" It is littered with small shells and seaweed",
      "sea floor","You can see the sea floor just below your feet."
                 +" It is littered with small shells and seaweed",
      "shells","Small sea shells litter the sea floor",
      "seaweed","There are several kinds of seaweed growing all over"
               +" the sea floor",
    });
    RP("/players/sauron/wreck/rooms/noutside_water_room");
  }
}
