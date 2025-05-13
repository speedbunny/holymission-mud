
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
    if (flag == 0)
    {
       dest_dir =
       ({
          PATH+"cellar_west","south",
          PATH+"dirty_corridor","north",
        });

        short_desc = "You are in a narrow corridor";
        long_desc = BS(
        "You are in a narrow corridor, it is damp and dark.");
        items =
        ({
        "bottom","The bottom is mad of bred wood",
        "ceiling","The ceiling is made of red bricks",
        "walls","The walls are made of red bricks",
        "corridor","It looks very dark",
        });
    }
}

