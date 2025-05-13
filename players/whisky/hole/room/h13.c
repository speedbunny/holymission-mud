 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 2)
  {
    CM("black_drake");
    CM("black_drake");
  }
   if (arg) return;
   set_light(0);
   short_desc = "In a dark hole";
   no_castle_flag = 0;
   long_desc = BS(
        "You are now on the fourth floor of the black hole. "
      + "The air gets hotter and hotter and it's rather wet here. "
      + "A tiny corridor leads further to the west and down.");
    dest_dir = 
        ({
      PATH+"h12","west",
      PATH+"h16","down",
        });
}
 
