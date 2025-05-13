 
  /* file fixed by haplo 3-27-95 */

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
       "You find yourself on a sandy beach. The sun is shining "
      + "and you get the feeling that you might stay here longer. "
      + "To the north you see some palm trees. To the west you see "
      + "a big black rock and you can hear the rumbling noise of "
      + "the volcano.");
    items = ({
              "rock","A big black rock",
              "palm trees","20 feet high palm-trees",
              "trees","20 feet high palm-trees"
            });
    dest_dir = 
        ({
        PATH+"island1", "southeast",
        PATH+"island6", "north",
        PATH+"island3", "east",
        });
     CO("beer");
}
 
