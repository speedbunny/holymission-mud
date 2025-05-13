
/* cp7 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "A bend in the path";
         long_desc = SIGHT+BS(
         "You are walking on a mountain path. The path leads further "+
         "up the mountain and back to the east. Not far away "+  
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
             PATH+"cp8","up",
             PATH+"cp6","east",
         });
      }
}


  
    
    

