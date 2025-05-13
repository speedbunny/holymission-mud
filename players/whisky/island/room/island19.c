 
 
inherit "room/room";
#include "../island.h"

void reset(int arg) 
{

   if (filter_live(this_object()) < 1)
      CM("minorva");
     
    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
          "You have nearly reached the top of the volcano. "
        + "The air is getting hotter and hotter and the gas coming "
        + "from the volcano nearly makes you unconscious. "
       + "You can't see anything through the dust and you can hear "
        + "a strange growling coming from the top of the volcano.");
    items = ({
           "bottom","A black stony bottom"
            });
    dest_dir = 
        ({
        PATH+"island14", "down",
        PATH+"island23", "north",
        PATH+"island18", "up",
        });
}
 
