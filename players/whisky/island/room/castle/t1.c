
/* t1 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Tunnel entrance";
         long_desc = 
         BS(
         "You are standing in front a big dark, tunnellike cave "+
         "leading deep into the mountain. To the south you can see "+
         "a small naturepath and a long coast, with seagulls flying "+
         "over the wild sea.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "beach","A long sandy beach"
            "tunnel","A big dark tunnel, you wonder who is living here",
            "cave","A big dark tunnel, you wonder who is living here",
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
             PATH+"t2","north",
             PATH+"p16","south",
         });
      }
}

    
    

