 

inherit "room/room";
#include "../island.h"


void reset(int arg) 
{
  if (filter_live(this_object()) < 2)
  {
    CM("native");
    CM("monkey");
  }
  if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
         "The air is full of ash-parts that you can't hardly see anything. "
        + "To the west a small part leads down and to the east and north "
        + "you can see the air getting thicker and fuller of ash-parts. ");
    
    dest_dir = 
        ({
        PATH+"island11", "down",
        PATH+"island17", "north",
        PATH+"island13", "east",
        });
}
 
