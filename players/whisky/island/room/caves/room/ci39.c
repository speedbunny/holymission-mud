
/* ci39 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
         CM("troll");
         CM("guard");
         CM("boy");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "At the northern end of a big hallway";
        long_desc = BS(
        "You are standing at the northern end of a big hallway. To the "+
        "south you can see the centre. All around you  there are huge "+
        "stone monoliths. You can see shadows moving behind them. "+
        "The hallway continues into a dark corridor to the north.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood",
         "corridor","A long, dark corridor",
         "monoliths","Big monoliths made of stone",
        });
      }
     dest_dir = 
     ({
       PATH+"ci36","south",
       PATH+"ci40","north",
     });
}
