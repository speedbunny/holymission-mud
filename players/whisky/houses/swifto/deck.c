
/* bed */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         short_desc = "On the deck of Swifto's house";
         long_desc = BS(
         "You are standing on the deck of Swifto's house "+
         "It's a large deck where you can overlook the whole "+
         "picturesque lake. In the middle of the deck is a big "+
         "swing big enough for two looking out over the lake.");
        
        items =
        ({
         "deck","A large deck with a good overlook ove the see",
         "swing","A beautiful swing",
         "lake","You see the beautiful blue lake",
        });

         dest_dir =
         ({
           PATH+"entrance","south",
           PATH+"swing","swing",
         }); 
     }
}
