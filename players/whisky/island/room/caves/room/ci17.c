
/* ci17 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 2)
     {
        CM("boy");
        CM("boy");
        CM("boy");
        CM("boy");
     }
     if (!present("orc chef de la cuisine",this_object()))
         CM("chef");
     if (flag == 0)
     {
        set_light(0);
        short_desc = "Inside the orcish kitchen";
        long_desc = BS(
        "You have entered a small, dark hole in the eastern part "+
        "of the orc caves. There is a campfire in the middle of "+
        "this place as some roasters and other bonecutting stuff "+
        "lying in the corner. The walls are full of human blood "+
        "and it smells like burned human flesh here. This looks "+
        "like this lace is the 'Kitchen' of the secret orc cave.");
        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "campfire","There is a campfire in the middle of this place",
         "roasters","Roasters and other kitchenstuff is lying in the corners",
        });
      }
     dest_dir = 
     ({
       PATH+"ci15","east",
     });
}
