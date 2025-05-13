
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
   if (flag == 0)
   {
      dest_dir =
      ({
         PATH+"inner_hall","north",
         PATH+"stairway_up","up",
         PATH+"stairway_down","down",
       });
       short_desc = "A landing in stairway";
       long_desc = BS(
       "You are in a landing on the stairway. The stairway goes up " +
       "to another place there ia a big hall to the north.");
       items =
       ({
        "hall","There is a big hall to the north",
        "stairway","It's made of wood",
        "ceiling","It's made of red bricks",
        "walls","They are made of red bricks",
        "bottom","The bottom is made of fouly wood",
       });
   }
}

