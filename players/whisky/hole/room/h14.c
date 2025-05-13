

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
      + "It's incredibly hot and wet here. A tiny corridor leads "
      + "further to the east and up. A black cave leads to the west "
      + "and a portal glows on the wall.");
    dest_dir = 
    ({
      PATH+"h13","east",
      PATH+"cave","west",
      PATH+"h11","up",
    });
}

