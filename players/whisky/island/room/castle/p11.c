

/* p11 */

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
         "You are walking staight up a small nature path. The rocks to "+
         "the east and west still hinder your view. "+
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
             PATH+"p12","northwest",
             PATH+"p10","down",
         });
      }
}

    
    

