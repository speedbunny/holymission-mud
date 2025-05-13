 
 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 1)
      CM("drunken_drake");

    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
        "You are now on the fifth floor of the black hole. "
      + "It's incredibly hot and wet here. A tiny corridor leads "
      + "further to the west and down.");
    dest_dir = 
        ({
      PATH+"h14","west",
      PATH+"h17","down",
        });
}
 
