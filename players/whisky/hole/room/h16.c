 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
        "You have now entered the fifth floor of the black hole. "
      + "It's incredible hot and wet here. A tiny corridor leads "
      + "further up, down and the Zombie Bar to the east.");
    dest_dir = 
        ({
      PATH+"h13","up",
      PATH+"h18","down",
      PATH+"zombie_bar","east",
        });
}
 
