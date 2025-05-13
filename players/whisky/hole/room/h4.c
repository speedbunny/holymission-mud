 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
   if (filter_live(this_object()) < 2)
   {
    CM("subversive");
    CM("subversive");
   }
   if (arg) return;
   set_light(0);
   short_desc = "In a dark hole";
   no_castle_flag = 0;
   long_desc = BS(
        "You are now on the second floor of the black hole. "
      + "It's really wet here but a little bit warmer. A tiny "
      + "corridor leads further to the east and down.");
items = ({ "corridor","a tiny little corridor"});
    dest_dir = 
        ({
      PATH+"h5","east",
      PATH+"h6","down",
        });
}
 
