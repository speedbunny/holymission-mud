
/* t3 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Inside a dark tunnel";
         long_desc = 
         BS(
         "You are sneaking inside a long dark tunnel. There are "+
         "big black stones all around you. Far to the south you see "+
         "some beams of light illuminating parts of this dark place.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t4","north",
             PATH+"t2","south",
         });
      }
}

    
    

