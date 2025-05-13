/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Gold Coast";
        long_desc=
  "Gold Coast is the place to visit whenever you are going to a beach.\n"+
  "It has warm weather for almost all year around and it is covered with\n"+
  "golden sand. It has been an old tradition for great adventurers to\n"+ 
  "come here to relax and enjoy themself in the sun. You are tempted to\n"+
  "swim into the water.\n"; 
        
        dest_dir=({ 
            ROOM + "shore1", "north",
            ROOM + "shore3", "swim",
            ROOM + "shore7", "south",
                  });
        items=({
  "sand","Fine golden sand",
               });
        smell = "Smell of salt water";
  
     }

init()
{
  ::init();
}
