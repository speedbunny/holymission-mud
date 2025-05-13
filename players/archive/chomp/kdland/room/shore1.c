/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Great Barrier Reef";
        long_desc=
  "You have arrived at the famous Great Barrier Reef, the only coral reef\n"+
  "of its kinds in all realms. The surrounding water in crystal clear,\n"+ 
  "you can see colourful corals and sea monsters under. You can not resist\n"+ 
  "to dive into the water.\n";
        
        dest_dir=({ 
            ROOM + "shore2", "dive",
            ROOM + "shore8", "south",
            ROOM + "intersc", "west",
                  });
        items=({
  "tree","It is a big and solid pine tree",
  "water","So fresh and crystal clear",             
               });
        smell = "You smell fresh air";
  
     }

init()
{
  ::init();
}
