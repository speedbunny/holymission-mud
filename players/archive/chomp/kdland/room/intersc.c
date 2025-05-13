/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Intersection";
        long_desc=
  "You have arrived at an intersection that directs you to various places\n"+
  "in the Dreamland. You notice a big tree and begin to enjoy the shade.\n"+
  "It is definitely cooler and more peaceful here. You see a bushland\n"+ 
  "to the south, a zoo area to the west and small shrubs to the north.\n"+ 
  "To the east you can see sparkling of sunlight reflected by blue sea\n"+ 
  "water on the beach. The water is so inviting...\n"; 
        
        dest_dir=({ 
            ROOM + "entry", "north",
            ROOM + "shore1", "east",
            ROOM + "land1", "south",
            ROOM + "zoo1", "west",
                  });
        items=({
  "tree","A big and solid pine tree",
  "water","The water is to the east, it looks so inviting...",
               });
        smell = "Hhhmmm......fresh air...";
  
     }

init()
{
  ::init();
}
