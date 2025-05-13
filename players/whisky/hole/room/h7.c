 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 2)
  {
    CM("snake");
    CM("snake");
  }
   set_light(0);
   short_desc = "In a dark hole";
   no_castle_flag = 0;
   long_desc = BS(
        "You are now on the second floor of the black hole. "
      + "It's really wet here but a bit warmer. A tiny corridor leads "
      + "further to the west and down.");
    dest_dir = 
        ({
      PATH+"h6","west",
      PATH+"h10","down",
        });
}
 
