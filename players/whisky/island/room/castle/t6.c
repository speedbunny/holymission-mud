
/* t6 */

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
         "Outch, you are running against a wall of stones. But toutching "+
         "yourself carefully further you find out that the tunnel leads "+
         "further to the west. It looks as if there is a bend in the cave.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t7","west",
             PATH+"t5","south",
         });
      }
}

    
    

