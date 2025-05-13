/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "In water";
        long_desc=
  "You are diving in the most beautiful water you have ever seen.\n"+
  "There are many corals and sea monsters, in all sort of beautiful\n"+
  "colours and shapes that you have not seen before.\n";
        
        dest_dir=({ 
            ROOM + "shore3", "south",
            ROOM + "shore1", "up",
                  });
        items=({
  "water","Salty water",
               });
        smell = "You are too busy swimming";
  
     }

init()
{
  ::init();
}
