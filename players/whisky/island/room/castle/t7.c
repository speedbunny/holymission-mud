
/* t7 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "A bend in the tunnel";
         long_desc = 
         BS(
         "You are standing next to a bend in the dark tunnel. In the "+
         "distance you see some beams of light illuminating parts of "+
         "this cave. To the east the tunnel winds itself to a darker "+
         "place.");  
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t6","east",
             PATH+"t8","north",
         });
      }
}

    
    

