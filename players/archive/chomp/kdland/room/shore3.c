/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "In water";
        long_desc=
  "You are swimming in the Gold Coast beach. You feel the waves are\n"+
  "a bit rough here, but you rather enjoy them. As you are washed away\n"+
  "from the coast, you notice a little island in the middle of the sea.\n"+
  "It might be an empty island...\n";
        
        dest_dir=({ 
            ROOM + "shore2", "north",
            ROOM + "island1", "island",
            ROOM + "shore4", "south",
            ROOM + "shore8", "up",
                  });
        items=({
  "island","You see a little island in the distance",
  "water","Salty water",
               });
        smell = "You are too busy swimming";
  
     }

init()
{
  ::init();
}
