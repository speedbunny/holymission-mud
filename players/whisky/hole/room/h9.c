 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 2)
  {
    CM("zombie");
    CM("zombie");
    CM("zombie");
  }
   if (arg) return;
  set_light(0);
  short_desc = "In a dark hole";
  no_castle_flag = 0;
  long_desc = BS(
        "You are on the third floor of the black hole. "
      + "It's really warm and wet here. A tiny corridor leads further "
      + "to the east, west and down.");
    dest_dir = 
        ({
      PATH+"h10","east",
      PATH+"h8","west",
      PATH+"h12","down",
        });
}
 
