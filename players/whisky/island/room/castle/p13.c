
/* p13 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "On a small mountain path";
         long_desc = SIGHT+
         BS(
         "You are wandering on the mountain path. To the east you can "+
         "overlook the beach and to the west you see high snowcovered "+
         "mountains. Behind the mountains, looking through a ravine "+
         "you can see another island with an active volcano.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "distance","In the near distance you can see a ruin",
            "ruin","An old looking, wrecked castle",
            "castle","An old looking, wrecked castle",
            "beach","A long sandy beach"
            "waves","Big waves are rolling towards the shore",
            "seagulls","Seagulls are flying over the water",
            "island","To the east you see another island\n"+
                     "with an active volcano",
            "volcano","A big active volcano",
            "ezo","To the north you can see the island of ezo",
            "coast","Far to the south you can see a long coast and a village"+
            "city","A small village with a little church a chapel and\n"+
                   "some houses. Out of a big blue lake a river floats\n"+
                   "through the village ending in a delta in the blue\n"+
                   "sea",
         });
         dest_dir =
         ({
             PATH+"p14","north",
             PATH+"p12","down",
         });
      }
}

    
    

