
/* cp3 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "On a path to a strange building";
         long_desc = SIGHT+BS(
         "You are wandering on the steep path. To far the south you can "+
         "see the entrance to a long dark tunnel. In the far distance "+
         "you can see a dark building one the western side of the "+
         "mountain. Far to the north you can see the island of ezo."); 
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
             PATH+"cp4","northwest",
             PATH+"cp2","down",
         });
      }
}


  
    
    

