 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
        "You have now entered the second floor of the black hole. "
      + "It's really wet here but a bit warmer. A tiny corridor leads "
      + "further to the east and up.");
    dest_dir = 
        ({
      PATH+"h7","east",
      PATH+"h3","up",
        });
}
 
