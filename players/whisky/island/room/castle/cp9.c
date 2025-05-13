
/* cp9 */

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
         "You are standing in front of an old wrecked castle. "+
         "The whole building looks dark and cold. "+
         "Ravens are circling around in the air. To the west if you "+
         "can walk to the gates of this strange building.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "ruin","An old looking, wrecked castle",
            "building","An old looking, wrecked castle",
            "castle","An old looking, wrecked castle",
            "ravens","Ravens are circling high in the air",
            "gates","strong wooden gates",
         });
         dest_dir =
         ({
             PATH+"cp10","west",
             PATH+"cp8","south",
         });
      }
}


  
    
    

