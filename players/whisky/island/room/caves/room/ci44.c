
/* ci44 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
        CM("troll");
        CM("troll");
        CM("troll");
        CM("troll");
        CM("troll");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "The sleeping chamber of the troll guards";
        long_desc = BS(
        "You have entered the big sleeping chamber of the troll "+
        "guards. You can see loud snoring trolls on the bottom. "+
        "One troll who was awake and playing with himself thunders: "+
        "'Who is here ?' and wakes the other trolls. In the middle "+
        "of this place is a campfire and there are old curtains "+
        "lying on the bottom.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "curtains","The curtains are made of wool",
         "boulder","A big round boulder, heavy but maybe to push aside",
         "campfire","Just a campfire to have it warm during winternights",
        });
      }
        dest_dir = 
       ({
          PATH+"ci43","east",
       });
}



