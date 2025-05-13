

inherit "room/room";
#include "../guild.h"

void reset(int arg) 
{
   if (filter_live(this_object()) < 2)
   {
     CM("pmonk");
     CM("pmonk");
     CM("pmonk");
   }
    if (arg) return;
    set_light(1);
    short_desc = "In a chapel"; 
    long_desc =  BS(
          "This is one of the eastern parts of the monk chapel. "
        + "It's a silent place, where the monks often pray to their gods "
        + "for more luck in daily life. A little corridor leads further " 
        + "to the north, west and south.");
    items = ({ 
            "walls","White stone walls",
            "bottom","A brown wooden bottom"
             });
    dest_dir = 
        ({
        PATH+"c9","north",
        PATH+"c5","west",
        "/players/sauron/guild/room","south",
        });
}
 
