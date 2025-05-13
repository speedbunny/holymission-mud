/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(0);
        short_desc= "Cave";
        long_desc=
  "You are in a small and dark cave where wombats live. They are rather\n"+
  "slow and harmless monsters, but they can be aggressive if attacked\n"+
  "or disturbed.\n"; 
        
        dest_dir=({ 
            ROOM + "zoo1", "southeast",
            ROOM + "zoo6", "south",
            ROOM + "zoo4", "southwest",
                  });
        items=({
  "cave","A small cave, you have to duck yourself",
               });
        smell = "It's rather humid and smelly here";
  
     }

init()
{
  ::init();
}
