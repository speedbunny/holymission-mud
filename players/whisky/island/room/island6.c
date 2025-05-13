
    /* fixed by haplo on 3-27-95 */

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
   if (filter_live(this_object()) < 2)
   {
     CM("monkey");
     CM("monkey");
   }
   if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
          "You are standing in the mittle of a row of palm-tees. "
        + "The bottom is full of white sand and you can hear the shrieks of "
        + "the famous island monkeys playing around and gathering coconuts. "
        + "To the north you see a big black rock and to the east some "
        + "more palm-trees. To the west you see a little rock.");
    items = ({
         "trees","100 feet high palm-trees",
         "palm-trees","100 feet high palm-trees",
         "rock","A little black rock",
         "bottom","A fine sandy bottom"
            });
    dest_dir =({ 
        PATH+"island5","up",
        PATH+"island2","south",
        PATH+"island7","east",
        });
    CO("tree");
}
