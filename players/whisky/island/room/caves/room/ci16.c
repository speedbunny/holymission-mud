
/* ci15 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 2)
     {
        CM("warrior");
     }
     if (sizeof(all_inventory()) < 15)
     {
        CO("apple");
        CO("apple");
        CO("apple");
        CO("apple");
        CO("cider");
        CO("cider");
        CO("cider");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "Inside a storeage room";
        long_desc = BS(
        "You have entered a small, dark hole in the eastern part "+
        "of the orc caves. This room looks empty and seems to be "+
        "build up to store things. Maybe for the kitchen of the "+
        "orc chief ? To the west a small corridor leads back to "+
        "the cavecrossing."); 
        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
        });
      }
     dest_dir = 
     ({
       PATH+"ci15","west",
     });
}
