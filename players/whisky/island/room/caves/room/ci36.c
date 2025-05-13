
/* ci36 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
         CM("peasant");
         CM("peasant");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the centre of a big hallway";
        long_desc = BS(
        "You are standing in the centre of a big hallway. To the "+
        "east, west and north the hallway continues. All around you "+
        "there are huge stone monoliths. You can see shadows moving "+
        "behind them. You can leave this hallway through a long, "+
        "dark corridor to the south.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "cave-in","There is a big, lit cave in to the west",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood",
         "monoliths","Big monoliths made of stone",
        });
      }
     dest_dir = 
     ({
       PATH+"ci39","north",
       PATH+"ci35","south",
       PATH+"ci37","west",
       PATH+"ci38","east",
     });
}
