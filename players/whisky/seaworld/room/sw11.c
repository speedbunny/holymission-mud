#include "../seaworld.h"

void reset(int arg) 
{
    ::reset(arg);

      if (filter_live(this_object()) < 2)
      {
	CM("stone_fish");
	CM("stone_fish");
      }

    if (arg) return;

    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
      "You have now entered the stone fish area of the sea. "+
      "The water is here a little bit colder but pleasant. "+
      "The sun is shining through the water. To the north "+ 
      "the sea gets darker.");

    items = ({
      "bottom","A cold sandy sea bottom",
      "water","Clear sea water" });

    dest_dir = ({
      PATH+"sw17","east",
      PATH+"sw5","west",
      PATH+"sw10","north",
      PATH+"sw12","south" });
}
