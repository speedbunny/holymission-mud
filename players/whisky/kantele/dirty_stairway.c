
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
       dest_dir =
       ({
          PATH+"dirty_anteroom","south",
          PATH+"dirty_corridor","up",
       });
       short_desc = "You are in a stairway";
       long_desc = BS(
       "You are at the bottom of a stairway, you can go up or enter "+
       "a small room to the south.");
       items =
       ({
        "stairway","The stairway is made of oak",
       });
     }
}

