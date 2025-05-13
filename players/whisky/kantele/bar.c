


/* bar */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "A small, private barroom";
         long_desc = BS(
         "You are in a small private bar, you can exit west behind the bar " +
         "or you can enter the trophy room to the south, to the north you " +
         "can see into the living room.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
         });
         dest_dir =
         ({
             PATH+"living_room","north",
         });
      }
}

