 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 1)
     CM("mad_drake");

    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
        "You have now entered the sixth floor of the black hole. "
      + "It's so hot here that you feel you could die. "
      + "You suddenly get the strange feeling that there must be "
      + "a great evil nearby.\n"
      + "A tiny little corridor leads further to the east and up.");
    dest_dir = 
        ({
      PATH+"h15","up",
      PATH+"h18","east",
        });
}
 
