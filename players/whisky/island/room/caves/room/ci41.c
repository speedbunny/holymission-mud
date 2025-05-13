
/* ci40 */

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
        "You are walking in the dark, secret orc caves. "+
        "To the west the corridor leads further. The bottom is "+
        "covered with moss and the air smells a bit sweet, just "+
        "like the odour of dead human corpses. On the wall you see "+
        "some big spots of blood. The dark passage leads back to "+
        "the south.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood", 
         "moss","Green wet moss",
        });
      }
     dest_dir = 
     ({
       PATH+"ci42","west",
       PATH+"ci40","south",
     });
}
