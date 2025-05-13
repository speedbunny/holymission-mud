
/* cp7 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "Next to a big black ruin";
         long_desc = SIGHT+BS(
         "You are standing on the mountainpath next to a big wracked "+
         "castle. Ravens are circling around in the air. It's maybe "+
         "better to go back down the mountain path.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "distance","In the near distance you can see a ruin",
            "ruin","An old looking, wrecked castle",
            "building","An old looking, wrecked castle",
            "castle","An old looking, wrecked castle",
            "ravens","Ravens are circling high in the air",
         });
         dest_dir =
         ({
             PATH+"cp9","north",
             PATH+"cp7","down",
         });
      }
}


  
    
    

