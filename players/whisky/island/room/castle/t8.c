
/* t8 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Near the tunnel exit";
         long_desc = 
         BS(
         "You are standing in a big dark tunnel. There are big black "+
         "stones all around you. To the north you see some beams of "+
         "light illuminating the tunnel. To the south the tunnel "+
         "leads further into the darkness.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t9","north",
             PATH+"t7","south",
         });
      }
}

    
    

