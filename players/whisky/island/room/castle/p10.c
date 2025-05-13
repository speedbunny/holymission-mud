

/* p10 */

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
         "You are standing on the beginning of a small nature path. "+
         "When you look up you can see this small path winding itself "+
         "up a mountain. The ground is covered with black stones. "+
         "Far to the east you can hear the noise of the wild sea.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "mountain","A very high mountain, althought you only\n"+
                       "can see a part of it from your point of view",
         });
         dest_dir =
         ({
             PATH+"p9","south",
             PATH+"p11","up",
         });
      }
}

    
    

