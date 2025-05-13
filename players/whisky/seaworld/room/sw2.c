
#include "../seaworld.h"

void reset(int arg) 
{
   ::reset(arg);

    if (filter_live(this_object()) < 2)
       CM("crab");

   if (arg) return;
    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
    "You have now entered one of the western parts of the sea. " +
    "The water is warm and pleasant here and the sun is shining " +
    "through the water, so that you get the feeling that you could stay "+
    "here forever.");

    items = ({ "bottom", "You see a fine sandy bottom" });

    dest_dir = ({
      PATH+"sw6", "east",
      PATH+"sw3", "south", });
}
