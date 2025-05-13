
/* ci9 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 2)
     {
         CM("peasant");
         CM("peasant");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the orc Caves";
        long_desc = BS(
        "You are standing in the large orc caves. Far to "+
        "the northeast you can hear some prayers. It "+
        "smells a bit sweet here, just like a huge heap of "+
        "dead humanoid corpses. The bottom is covered with "+
        "white bones and the stony walls are colored with "+
        "blood.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
        });
        dest_dir = 
        ({
         PATH+"ci10","east",
         PATH+"ci7","southwest",
        });
     }
}


