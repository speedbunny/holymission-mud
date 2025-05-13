// Fixed the long description, was missing a ) 040394 Colossus 


inherit "room/room";
#include "../island.h"

void reset(int arg) 
{

    if (filter_live(this_object()) < 2)
	CM("monkey");

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
      "You are standing in the middle of a row of palm-trees. "
      + "The bottom is full of white sand and you can hear the shrieks of "
      + "the famous island monkeys playing around and gathering bananas. "
      + "To the north you see a big rock and to the east some more "
      + "palm-trees. To the south you see the beautiful beach and the blue sea.");
    items = ({
      "trees","100 feet high palm-trees",
      "palm-trees","100 feet high palm-trees",
      "rock","A big black rock",
      "sea","The clear blue sea",
      "beach","A long sandy beach",
      "bottom","A fine sandy bottom"
    });
    dest_dir = 
    ({
      PATH+"island3","south",
      PATH+"island8","east",
      PATH+"island6","west",
    });
    CO("tree");
}
