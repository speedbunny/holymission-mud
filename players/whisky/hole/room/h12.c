 
 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
 /* out
    if (filter_live(this_object()) < 1)
       CM("demon");
   */
    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
        "You have now entered the fourth floor of the black hole. "
      + "The air gets hotter and hotter and it's rather wet here. "
      + "A tiny corridor leads further to the east, west and up.");
    dest_dir = 
        ({
      PATH+"h11","west",
      PATH+"h13","east",
      PATH+"h9", "up",
        });
}
 
query_light() {
    return 0;
}
