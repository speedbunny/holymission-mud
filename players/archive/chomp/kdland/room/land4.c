/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(-1);
        short_desc= "Jenolan Cave";
        long_desc=
  "Inside Jenolan Cave, the main one of the hundred ancient caves formed\n"+
  "thousand of years ago. You can see beautifully sparkling and colourful\n"+
  "stalactites above you and stalacmites on the ground, which reflect\n"+ 
  "the light from your lightsource with radiance, leaving you speechless.\n"+ 
  "There is a little creek across the cave.\n";
        
        dest_dir=({ 
            ROOM + "land1", "north",
            ROOM + "land3", "east",
            ROOM + "land5", "west",
                  });
        items=({
  "cave","A beatiful old cave with marblish coloured walls",
  "creek","A little creek with water flowing slowly",             
  "ground","Shiny and a little slippery",
  "stalacmites","Shimmering with colourful radiance",
  "stalactites","Shimmering with colourful radiance",
  "water","The water is crystal clear",
               });
        smell = "It's cold and dry here";
  
     }

init()
{
  ::init();
}
