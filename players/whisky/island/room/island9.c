 
inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
  if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
          "You are standing at the beach the sun is shining and to the west "
        + "you can see some palm-trees. But if you look down you see some "
        + "footsteps and you can hear the drum-roll getting louder and "
        + "louder.");
    items = ({
             "trees","100 feet high palm-trees",
             "palm-trees","100 feet high palm-tees",
             "footsteps","Big strange footsteps"
            });
    dest_dir = 
        ({
        PATH+"island8", "west",
        PATH+"island15", "east",
        });
}
