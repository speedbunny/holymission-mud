/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Open land";
        long_desc=
  "You have arrived at an open land, but there are still some trees and\n"+ 
  "bushes around. Here is where kangaroos live and bounces around the\n"+
  "place happily, searching for food. You notice they are coming to you\n"+
  "and looking at you cutely.\n";
        
        dest_dir=({ 
            ROOM + "zoo5", "cave",
            ROOM + "zoo1", "east",
            ROOM + "zoo3", "south",
            ROOM + "zoo4", "west",
                  });
        items=({
  "bushes","Thin bushes",
  "land","Dry and grassy land",
  "tree","A big gum tree",
               });
        smell = "The air is kinda smelly here";
  
     }

init()
{
  ::init();
}
