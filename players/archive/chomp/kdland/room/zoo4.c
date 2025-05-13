/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Swamp";
        long_desc=
  "You at a dirty swamp. The water is so dirty and brown, you wonder\n"+
  "what monsters would live here. You can see a cave in the northernly\n"+ 
  "direction. In the distance, you notice some tree trunks floating and\n"+ 
  "coming toward you. But when you realise that they are NOT tree trunks,\n"+ 
  "you have been surrounded by vicious monsters...\n";
        
        dest_dir=({ 
            ROOM + "zoo5", "cave",
            ROOM + "zoo6", "east",
            ROOM + "zoo3", "southeast",
                  });
        items=({
  "swamp","A dirty little swamp",
  "water","Yuk ! It's dirty...",             
               });
        smell = "It's rather humid here";
  
     }

init()
{
  ::init();
}
