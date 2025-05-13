

/* lab */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Inside Kantele's laboratory";
         long_desc = BS(
         "You are in Kantele's laboratory, you can enter the hall " +
         "to the east. The room  is covered " +
         "with strange devices, an odd smell penetrates the air.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
         });
         dest_dir =
         ({
             PATH+"upper_hall","east",
         });
      }
}

