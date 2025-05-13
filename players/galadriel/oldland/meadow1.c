inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg)  {
    set_light(1);
    short_desc = "Meadow";
    long_desc = 
        "You standing on a meadow which is covered with flowers.\n";
    dest_dir = ({
        LAND + "meadow2",   "north",
        ROAD + "southgate", "east",
        LAND + "pasture",   "west"
       });
    items = ({
      "flowers","There are flowers in all colors. They smell wonderful"
    });
   }
}

move(dir) {
   if (!dir) dir=query_verb();
   return (this_player()->query_stay_garden() && (dir=="east") )?
     ::move("west") : ::move(dir);
}
