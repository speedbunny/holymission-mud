

inherit "room/room";
#include "../guild.h"


void reset(int arg) 
{
   if (filter_live(this_object()) < 4)
   {
    CM("smonk");
    CM("smonk");
    CM("smonk");
    CM("smonk");
   }
    if (arg) return;
    set_light(1);
    short_desc = "In a chapel"; 
    long_desc = BS(
    "This is one of the central point of the monk chapel. "
    + "It's the place with the best acoustics. A little "
    + "corridor leads further to the east west north and " 
    + "south.");
    items = ({ 
      "walls","White stone walls",
      "bottom","A brown wooden bottom"
    });
    dest_dir = 
    ({
      PATH+"c8","north",
      PATH+"c6","east",
      PATH+"c4","west",
      PATH+"c2","south"
    });
}

