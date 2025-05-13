

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
   if (filter_live(this_object()) < 1)
       CM("blue_dragon");

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
        "You are climbing up the volcano and you get a strange feeling. "
        + "The air is full with little ash particles and you can hear the "
        + "loud noise of the rumbling volcano. "
        + "To the east you can see some palm trees swaying in the breeze.");
    items = ({
          "volcano","A big black volcano",
          "palm trees","100 feet high palm trees",
          "trees","100 feet high palm trees",
          "bottom","A long sandy bottom"
            });
    dest_dir = 
        ({
        PATH+"island11", "north",
        PATH+"island6", "down",
        });
}

