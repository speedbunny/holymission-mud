/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Manly beach";
        long_desc=
  "The well known Manly beach where ironman adventurers competitions\n"+
  "are held frequently. Big waves are hurling toward you and sweeping\n"+
  "your feet, it's really peacefull here. Enjoy the waves.\n";
        
        dest_dir=({ 
            ROOM + "shore8", "north",
            ROOM + "shore4", "wave",
            ROOM + "shore6", "south",
                  });
        items=({
  "tree","It is a big and solid pine tree",
               });
        smell = "You are breathing to fresh air again";
  
     }

init()
{
  ::init();
}
