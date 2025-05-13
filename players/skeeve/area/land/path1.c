inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  object beekeeper;  
  if (!arg)  {
    set_light(1);
    short_desc = "path";
    long_desc =  "You are on a small path in the forest.\n";
    dest_dir = ({
        LAND + "forest0",     "north",
        ROAD + "bifurcation", "east",
        LAND + "meadow2",     "south",
        LAND + "fork",        "west"
       });
    items = ({
      "path",   "It's a small and lonesome path beetween high trees",
      "forest", "It's a dark and dangerous forest",
      "trees",  "It seems, that they are reaching the sky",
      "tree",   "So much trees"
    });
  }
  CASTLE->add_monster("beekeeper",this_object());
}

move(dir) {
   if (!dir) dir=query_verb();
   return (this_player()->query_stay_garden() && (dir=="east") )?
     ::move("west") : ::move(dir);
}
