

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
   ::reset(arg);
/* Commented out by Sauron 040595 as the room wasn't loading
   if (filter_live(this_object()) < 1)
      CM("zuluman");
*/

   if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
         "You have now entered the area of the dangerous zuluman. "
        + "Run away before he will come back to kill you. "
        + "To the north and east you see the blue sea. "
        + "and you can hear a strange drum-roll from the south.");
    items = ({
          "sea","The clear blue sea",
          "bottom","A fine sandy bottom"
            });
    dest_dir = 
        ({
        PATH+"island25", "southeast",
        });
}
