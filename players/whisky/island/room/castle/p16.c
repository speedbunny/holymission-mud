
/* p16 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "In front of a dark tunnel";
         long_desc = SIGHT+
         BS(
         "You are wandering on the mountain path. To the east you can "+
         "overlook the beach and to the west you see high snowcovered "+
         "mountains. Far to the south you see a long coast and seagulls "+
         "flying over the water. To the north you see the entrance of "+
         "a big, dark tunnel.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "beach","A long sandy beach"
            "tunnel","A big dark tunnel, you wonder who is living here",
            "waves","Big waves are rolling towards the shore",
            "seagulls","Seagulls are flying over the water",
            "coast","Far to the south you can see a long coast and a village"+
            "village","A small village with a little church a chapel and\n"+
                   "some houses. Out of a big blue lake a river floats\n"+
                   "through the village ending in a delta in the blue\n"+
                   "sea",
         });
         dest_dir =
         ({
             PATH+"t1","north",
             PATH+"p15","south",
         });
      }
}

    
    

