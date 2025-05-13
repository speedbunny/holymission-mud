/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Little Island";
        long_desc=
  "You are at the coast of an empty island. You notice that there is\n"+
  "hardly any sign of life here. You hear breezes of wind from leaves\n"+
  "of coconut trees surrounding you. It gives you an irie feeling...\n";
        
        dest_dir=({ 
            ROOM + "shore3", "back",
                  });
        items=({
  "island","Empty island",
  "trees","Coconut trees",
               });
        smell = "Smell of fresh coconuts from the trees";
  
     }

init()
{
  ::init();
}
