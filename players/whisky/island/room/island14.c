
 
inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
    if (filter_live(this_object()) < 1)
        CM("red_dragon");

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
          "The top of the volcano comes nearer and nearer. The air is "
        + "full of ash. You can smell a foul odor coming "
        + "from the volcano. To the east and south you can see the coast "
        + "of this island and to the north a small path is leading up.");
    items = ({
            "path","A small stony path",
            "coast","A long beautiful coast"
             });
    dest_dir = 
        ({
        PATH+"island13", "down",
        PATH+"island19", "up",
        });
}
