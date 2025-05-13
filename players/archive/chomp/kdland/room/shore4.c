/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "In water";
        long_desc=
  "You are swimming on the beach. The waves are getting bigger as you swim\n"+
  "further from the coast, they rock you rather violently. Maybe you should\n"+
  "go back ashore.\n";
        
        dest_dir=({ 
            ROOM + "shore3", "north",
            ROOM + "shore5", "south",
            ROOM + "shore7", "back",
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
