
/* cp1 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "At the entrance of a dark tunnel";
         long_desc = SIGHT+BS(
         "You are wandering on the steep path. Far to the south you can "+
         "see the entrance to a long dark tunnel. "+
         "Far to the north you can see the island of ezo."); 
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "distance","In the near distance you can see a ruin",
            "ruin","An old looking, wrecked castle",
            "castle","An old looking, wrecked castle",
            "ezo","To the north you can see the island of ezo",
         });
         dest_dir =
         ({
             PATH+"cp1","south",
             PATH+"cp3","up",
         });
      }
}


  
    
    

