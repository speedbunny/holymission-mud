 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
        "You have now entered the third floor of the black hole. "
      + "It's really warm and wet here. A tiny corridor leads further "
      + "to the west and up.");
    dest_dir = 
        ({
      PATH+"h9","west",
      PATH+"h7","up",
        });
}
 
