 
 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
    if (arg) return;
    set_light(0);
    short_desc = "In a dark hole";
    no_castle_flag = 0;
    long_desc = BS(
      "You have entered the black hole. You are now on the first floor. "
    + "It's a little bit cold and wet here. A tiny corridor leads further to "
    + "the west, east and down.");
    items = ({ "corridor","a tiny black corridor"});
    dest_dir = 
        ({
       PATH+"h1","west",
       PATH+"h3", "east",
       "players/whisky/garden/room/mousehole3","up",
       PATH+"h5","down",
        });
}
