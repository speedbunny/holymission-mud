

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
    if (filter_live(this_object()) < 2)
    {
	CM("red_dragon");
	CM("green_dragon");
    }

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
      "The top of the volcano is coming nearer and nearer. "
      + "The air is full of ask-parts. You can smell the bad "
      + "taste of gas coming out from the volcano. To the north "
      + "and west you can see the blue sea and the coast of the island. "
      + "To the east and south there is a small path leading up and down.");
    items = ({
      "bottom","A black stony bottom",
      "portal","Its a small glowing portal that is energized with light",
      "sea","The blue sea",
      "coast","A long sandy coast",
      "path","A small stony path"
    });
    dest_dir = 
    ({
      PATH+"island22", "up",
      PATH+"island17", "down",
    });
}
