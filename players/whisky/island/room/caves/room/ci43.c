
/* ci43 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 2)
         CM("boy");
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the secret orc chambers";
        long_desc = BS(
        "You are wandering in the dark, secret orc caves. "+
        "To the north the corridor leads further into a small "+
        "lit hallway. You can see some shadows next to the "+
        "entrance. To the west you hear some snoring and a noise "+
        "of strange creatures. The dark passage leads further to "+
        "the north and back to the south."); 

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "shadows","Looks like there are huge creatures",
         "blood","You see big spots of human blood", 
         "moss","Green wet moss",
        });
      }
     dest_dir = 
     ({
       PATH+"ci44","west",
       PATH+"ci45","north",
       PATH+"ci42","south",
     });
}
