
/* t4 */

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
         "You are sneaking inside a long dark tunnel. You are covered "+
         "by deep darkness. All around you there are big black stones. "+ 
         "It's a little bit cold here. You start to freeze.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t5","north",
             PATH+"t3","south",
         });
      }
}

    
    

