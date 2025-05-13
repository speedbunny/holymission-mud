/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Old mine";
        long_desc=
  "Here is the western side of the bushland, where most of the land\n"+
  "had been cleared for mining purposes. Adventurers used to come here\n"+
  "searching for fortune, in the now abandoned area.\n";
        
        dest_dir=({ 
            ROOM + "land1", "east",
            ROOM + "land5", "south",
                   });
        items=({
  "mine","You can only see empty holes on the ground",
  "ground","It's very undulating here",
               });
        smell = "The air is hot here";
  
     }

init()
{
  ::init();
}
