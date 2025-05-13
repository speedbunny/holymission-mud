/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "In water";
        long_desc=
  "Brrr...! You swim in cold blue sea water. It is very calm here, as\n"+ 
  "the bay is well protected from main ocean. You notice some dolphins\n"+ 
  "near you swimming and looping in the air.\n";
  
        dest_dir=({ 
            ROOM + "shore4", "north",
            ROOM + "shore6", "up",
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
