/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Desert";
        long_desc=
  "You are entering the bushland area, but the bushes are not very thick\n"+
  "here and the ground consists of mainly sand and grass. The bushes get\n"+
  "thicker westwards and there are caves to the south. Intersection is\n"+ 
  "to the north.\n";
        
        dest_dir=({ 
            ROOM + "intersc", "north",
            ROOM + "land2", "east",
            ROOM + "land4", "south",
            ROOM + "land6", "west",
                  });
        items=({
  "ground","It's sandy and a little grassy here",
  "bushes","Very scattered bushes",
               });
        smell = "You feel very hot here";
  
     }

init()
{
  ::init();
}
