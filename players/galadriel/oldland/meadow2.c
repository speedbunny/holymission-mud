inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg)  {
    set_light(1);
    short_desc = "Meadow";
    long_desc = 
        "You standing on a meadow covered with flowers.\n";
    dest_dir = ({
        LAND + "path1",  "north",
        ROAD + "road",   "east",
        LAND + "meadow1", "south",
        LAND + "path3",  "west"
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
