
/* ci37 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 4)
     {
         CM("peasant");
         CM("peasant");
         CM("shaman");
         CM("shaman");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "At the western end of a big hallway";
        long_desc = BS(
        "You are standing at the western end of a big hallway. To the "+
        "east you can see the centre. All around you  there are huge "+
        "stone monoliths. You can see shadows moving behind them. "+
        "To the east you see a big stone wall covered with spots "+
        "of human blood.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood",
         "monoliths","Big monoliths made of stone",
        });
      }
     dest_dir = 
     ({
       PATH+"ci36","east",
     });
}
