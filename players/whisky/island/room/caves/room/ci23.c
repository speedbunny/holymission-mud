
/* ci19 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 5)
     {
         CM("warrior");
         CM("shaman");
         CM("warrior");
         CM("guard");
         CM("guard");
         CM("boy");
     }
     if (sizeof(all_inventory()) < 20)
     {
         CO("morningstar");
         CO("morningstar");
         CO("morningstar");
         CO("boots");
         CO("boots");
         CO("axe");
         CO("jacket");
         CO("jacket");
         CO("dagger");
         CO("dagger");
     }
     if (flag == 0)
     {
        set_light(1);
        short_desc = "The armour and weapon orc caves";
        long_desc = BS(
        "You go down the stairway to enter a dark place hidden "+
        "place in the orc chambers. This place looks totally empty "+
        "without the weapons and armours lying around. The walls "+
        "are wracked and orc helpers are polishing stuff. This looks "+
        "like a good place to store weapons and armours. The only "+
        "exit is the stairway leading up.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "stairway","You see a small wooden stairway leading up",
        });
      }
     dest_dir = 
     ({
       PATH+"ci22","up",
     });
}
