
/* ci45 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the secret orc chambers";
        long_desc = BS(
        "You are wandering in the dark, secret orc caves. "+
        "To the north the corridor leads further into a small "+
        "lit hallway. You can see huge shadows of creatures next "+
        "entrance. Maybe you should go back now ? The dark passage "+
        "leads back to the south.");

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
       PATH+"ci46","north",
       PATH+"ci43","south",
     });
}
