
/* ci35 */

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
        "You are sneaking carefully in the dark, secret orc caves. "+
        "To the north the corridor leads into a hudge stone hallway "+
        "where you can see some big monoliths. Behind the monoliths "+
        "you can see some shadows moving around in groups of two. "+
        "The corridor leads back to the south.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "cave-in","There is a big, lit cave in to the west",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood",
         "monoliths","Big monoliths made of stone",
        });
      }
     dest_dir = 
     ({
       PATH+"ci36","north",
       PATH+"ci34","south",
     });
}
