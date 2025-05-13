/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Mountain's foot";
        long_desc=
  "You are at the foot of Snowy Mountain. The trees are taller here but\n"+
  "they are not very dense. You can see a little hut, by the creek which\n"+
  "flows down from the top of the mountain.\n";
        
        dest_dir=({ 
            ROOM + "land5", "down",
            ROOM + "mount2", "up",
                   });
        items=({
  "hut","Joey's little hut",
  "creek","A little creek with water flowing slowly",
  "ground","It consists of little rocks and rather grassy",
  "trees","White gum and eucalyptus trees",
  "water","The water is crystal clear",
               });
        smell = "You smell fresh mountain air";
  
     }

init()
{
  ::init();
}
