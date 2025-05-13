
/* ci15 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "A crossing in the secret orc caves";
        long_desc = BS(
        "You are standing on a crossing in the secret orc caves. "+
        "To the north, the corridor leads further and to the west "+
        "and east you see a small corridor leading towards a dark "+
        "place. The bottom is covered with moss and the air smells "+
        "here like roasted human flesh.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
        });
      }
     dest_dir = 
     ({
       PATH+"ci14","south",
       PATH+"ci16","east",
       PATH+"ci17","west",
       PATH+"ci18","north",
     });
}
