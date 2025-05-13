 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
   if (filter_live(this_object()) < 3)
   {
      CM("beetle");
      CM("beetle");
   }
   set_light(0);
   short_desc = "In a dark hole";
   no_castle_flag = 0;
   long_desc = BS(
       "You are now on the first floor of the black hole. "
     + "It's a little bit cold and wet here. A tiny corridor leads further to "
     + "the west and down.");
    dest_dir = 
        ({
      PATH+"h2","west",
      PATH+"h6","down",
        });
}
