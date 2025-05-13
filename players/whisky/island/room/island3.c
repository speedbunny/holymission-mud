 
  /*fixed by haplo on 3-27-95 */

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
    if (filter_live(this_object()) < 2)
        CM("blue_dragon");
    if (arg) return;
 
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
       "You find yourself on a sandy beach. The sun is shining. "
      + "and you get the feeling that you might stay here longer. "
      + "To the north you see some palm-trees. "
     + "The tops of the trees are swaying up and down. "
      + "and you wonder why you can't feel any wind.");
    items = ({
              "beach","A long sandy beach",
              "palm-trees","100 feet high palm-trees",
              "trees","100 feet high trees"
            });
    dest_dir = 
        ({
        PATH+"island1", "south",
        PATH+"island7", "north",
        PATH+"island2", "west",
        PATH+"island4", "east",
        });
     CO("shell");
}
 
