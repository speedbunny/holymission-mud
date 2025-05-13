/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Entrance";
        long_desc=
  "Welcome to the KANGAROOS DREAMLAND. You have arrive at the entrance.\n"+
  "It's so hot here that the harsh sunlight is begining to dry your skin.\n"+
  "Here you will find unique monsters and ground terrains, mostly found\n"+
  "only on the Australiana land. The entrance path is surrounded by shrubs\n"+
  "and it continues southward. You can see an intersection to the south\n"+ 
  "and your way back to the north.\n";
        
        dest_dir=({ 
            "players/chomp/workroom", "north",
            ROOM + "intersc", "south",
                  });
        items=({
  "entrance","A big word of 'WELCOME' is carved on it",
  "path","The path continues north and south",
  "shrubs","They are wild blackberry shrubs",
                });
        smell = "The air is hot and humid here";
  
     }

init()
{
  ::init();
}
