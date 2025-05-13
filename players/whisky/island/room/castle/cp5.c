
/* cp5 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "On a path to a ruin";
         long_desc = SIGHT+BS(
         "You are wandering on the steep path. To far the south you can "+
         "see the entrance to a long dark tunnel. Not far to the west "+
         "at the end of the path you can see a big ruin of a castle.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "distance","In the near distance you can see a ruin",
            "ruin","An old looking, wrecked castle",
            "building","An old looking, wrecked castle",
            "castle","An old looking, wrecked castle",
            "ezo","To the north you can see the island of ezo",
         });
         dest_dir =
         ({
             PATH+"cp6","north",
             PATH+"cp4","down",
         });
      }
}


  
    
    

