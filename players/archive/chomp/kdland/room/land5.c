/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Little hill";
        long_desc=
  "You are on a hilly ground with rather thick bushes, where you can see\n"+
  "a mountain and more trees in the distance of southwesternly direction.\n"+
  "There is a creek behind the bushes.\n";
        
        dest_dir=({ 
            ROOM + "land6", "north",
            ROOM + "land4", "east",
            ROOM + "mount1", "climb",
                   });
        items=({
  "bushes","Thick bushes",
  "creek","A little creek with water flowing slowly",
  "ground","It's very undulating here",
  "water","The water is crystal clear",
               });
        smell = "You smell fresh air";
  
     }

init()
{
  ::init();
}
