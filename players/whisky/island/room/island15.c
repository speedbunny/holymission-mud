 


inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
   if (filter_live(this_object()) < 2)
   {
     CM("native");
     CM("native");
     CM("native");
   }
   if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
          "You are standing on the beautiful beach and the sun is shining. "
        + "To the west you see some bushes. The bushes are moving their "
        + "tops and you suddenly get a strange feeling. Maybe some natives "
        + "are in the near.");
    items = ({
           "beach","A long sandy beach",
           "bushes","10 feet high bushes",
            });
    dest_dir = 
        ({
        PATH+"island25", "east",
        PATH+"island9", "west",
        });
}
