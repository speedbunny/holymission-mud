
#include "../seaworld.h"

void reset(int arg) 
{
   ::reset(arg); 

   if (filter_live(this_object()) < 2)
   {
     CM("dolphin");
     CM("dolphin");
   }
   if (arg) return;

    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
    "You have entered a warm and pleasant place in the sea. " +
    "The sun is shining through the water and you feel as if " +
    "could stay here for a while. This is the friendly dolphins' " +
    "favorite place. The bottom is sandy and to the " +
    "east lies a rock which blocks your way.");

    items = ({
      "rock", "You see a big black rock to the north",
      "bottom", "You see a fine sandy bottom", });
    dest_dir = ({
      PATH+"sw1", "west",
      PATH+"sw2", "north",
      PATH+"sw4", "south",});
}
