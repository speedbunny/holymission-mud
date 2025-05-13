
/* cellar_west */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
        short_desc = "In the western hall";
        long_desc = BS(
        "You are standing in the western hall, in the cellar of "+
        "the ruined castle. To the east you can see a wrecked "+
        "wooden stairway, or follow the passages to the north "+
        "or west.");

        items =
        ({
           "stairway","Well, it's wrecked but looks still in order",
        });

        dest_dir =
        ({
          PATH+"stairway_down.c","east",
         PATH+"kitiaras_hall","south",
          PATH+"dirty_passage.c","north",
        });
    }
}

