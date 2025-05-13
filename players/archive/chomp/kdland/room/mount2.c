/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Top of mountain";
        long_desc=
  "The top of the Snowy Mountain, which is the highest point in the whole\n"+
  "Australiana World. From here you can see beautiful views of green\n"+
  "forests and bushes in the north, rocks and caves in the northwest,\n"+
  "and shores in the northeast directions. There is a water spring here\n"+
  "and the water flows down a creek.\n";
        
        dest_dir=({ 
            ROOM + "mount1", "down",
                   });
        items=({
  "creek","A little creek with water flowing slowly",
  "ground","It's grassy here",
  "spring","A natural water spring",
  "water","The water is crystal clear",
               });
        smell = "You smell fresh mountain air";
  
     }

init()
{
  ::init();
}
