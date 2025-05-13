

inherit "room/room";
#include "../hole.h"

void reset(int arg) 
{
  if (filter_live(this_object()) < 2)
  {
    CM("earthworm");
    CM("earthworm");
  }
   set_light(0);
   short_desc = "In a black hole";
   no_castle_flag = 0;
   long_desc = BS(
    "You are on the first floor of the black hole; it's a little bit cold and "
  + "wet here. A tiny corridor leads further to the east.");
  items = ({ "corridor", "A tiny dark corridor"});
    dest_dir = 
        ({
      PATH+"h2","east",
        });
}
