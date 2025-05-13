
inherit "room/room";
#include "../guild.h"


void reset(int arg) 
{
   if (filter_live(this_object()) < 3)
   {
     CM("non");
     CM("non");
     CM("non");
     CM("non");
   }
    if (arg) return;
    set_light(1);
    short_desc = "In a chapel"; 
    long_desc =  BS(
          "This is one of the western parts of the monk chapel. "
          "It's a silent place where nuns whisper about their problems "+
             "and pray. A corridor leads to the east and to the "+
           "west.");
    items = ({ 
            "walls","White stone walls",
            "bottom","A brown wooden bottom"
             });
    dest_dir = 
        ({
        PATH+"c8","east",
        PATH+"c4","south"
        });
}
