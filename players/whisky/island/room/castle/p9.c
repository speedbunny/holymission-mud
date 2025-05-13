

/* p9 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "On a nature path";
         long_desc = BS(
         "You are crawling up the cliffs towars a steep nature path. "+
         "The ground is covered with black stones. Far to the east "+
         "you can hear the noise of the wild sea.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
         });
         dest_dir =
         ({
             PATH+"p8","down",
             PATH+"p10","north",
         });
      }
}

    
    

