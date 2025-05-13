/* Chomp's area - 7/3/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Zoo entrance";
        long_desc=
  "You are entering the zoo area of the Kangaroos Dreamworld, where many\n"+
  "monsters live. You can see a cave in the northernly direction and\n"+
  "trees in the south and westernly directions. The Zoo Keeper works\n"+ 
  "hard to keep this area in harmony. You can see a sign.\n";
        
        dest_dir=({ 
            ROOM + "intersc", "east",
            ROOM + "zoo2", "south",
            ROOM + "zoo6", "west",
            ROOM + "zoo5", "cave",
                  });
        items=({
  "ground","There are traces of monsters everywhere",
  "sign","Looks interesting. Maybe you should read it ?",             
               });
        smell = "The air is cool here";
  
     }

init()
{
  ::init();
  add_action("read","read");
}

read(str)  {
     if (!str)  {
        write("Read what ?\n");
        return 1;
                }
     if (str == "sign")  {
        write("\n");
        write("WARNING ! Do not disturb animals in this area.\n");
        write("\n");
        return 1;
            }
}
