
/* ci28 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 2)
         CM("shaman");
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the secret orc chambers";
        long_desc = BS(
        "You are sneaking through the secret orc caves. "+
        "To the north the dark corridor leads further and "+
        "to the south you can walk to a better lit place. "
        "It's completly silent here without the soft grunting "+
        "noises coming from the south. ");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
        });
      }
     dest_dir = 
     ({
       PATH+"ci29","north",
       PATH+"ci26","south",
     });
}
