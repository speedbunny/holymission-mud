/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Small rocky desert";
        long_desc=
  "You have arrived at a small rocky desert where there are only shrubs\n"+
  "here. You notice some Emus walking around and looking at you curiously.\n"+
  "Only strong monsters like them can live comfortably in this dry place.\n";
        
        dest_dir=({ 
            ROOM + "zoo6", "north",
            ROOM + "zoo2", "east",
            ROOM + "zoo4", "northwest",
                  });
        items=({
  "ground","Dry and rocky ground",
  "shrubs","Very thin shrubs",
               });
        smell = "The air is dry here";
  
     }

init()
{
  ::init();
}
