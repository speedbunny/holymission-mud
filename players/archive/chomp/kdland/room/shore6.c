/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Phillip Bay";
        long_desc=
  "The peaceful Port Phillip Bay at the furthest southeastern point of\n"+
  "the Australiana mainland. It is cool here, and you notice some big\n"+
  "and small penguins around.\n";
        
        dest_dir=({ 
            ROOM + "shore7", "north",
            ROOM + "shore5", "swim",
                  });
        items=({
  "ground","It is rocky and a little sandy",
               });
        smell = "The air is cool and fresh here";
  
     }

init()
{
  ::init();
}
