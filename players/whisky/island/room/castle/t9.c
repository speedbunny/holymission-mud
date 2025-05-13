
/* t9 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Next to the tunnel exit";
         long_desc = 
         BS(
         "You are standing next to the tunnel exit. To the north you "+
         "can see daylight illuminating this dark cave. All around "+
         "you there are big black stones. To the south the tunnel "+
         "leads back towards a darker place.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t10","north",
             PATH+"t8","south",
         });
      }
}

    
    

