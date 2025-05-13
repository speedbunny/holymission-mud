
/* ci33 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (!filter_live(this_object()))
     {
         CM("troll");
         CM("troll");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the secret orc chambers";
        long_desc = BS(
        "You are walking in the dark, secret orc caves. "+
        "To the north the corridor leads further. The bottom is "+
        "covered with moss and the air smells a bit sweet, just "+
        "like the odour of dead human corpses. On the wall you see "+
        "some big spots of blood. The dark passage leads back to "+
        "the east. Far to the north you can hear someone grunting "+
        "in a deep voice."); 

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "cave-in","There is a big, lit cave in to the west",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood",
        });
      }
     dest_dir = 
     ({
       PATH+"ci35","north",
       PATH+"ci33","east",
     });
}
