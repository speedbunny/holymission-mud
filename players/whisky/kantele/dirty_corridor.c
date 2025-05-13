
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
    if (flag == 0)
    {
       dest_dir =
       ({
           PATH+"dirty_passage","south",
           PATH+"dirty_stairway","down",
           PATH+"dirty_room","north",
       });
  
        short_desc = "You are in a dirty passage";
        long_desc = BS(
        "You are in a dirty passage, a stairway leads down and the " +
        "corridor continues to the north.");
        items =
        ({
         "ceiling","The ceiling is made of red bricks",
         "walls","The walls are made of red bricks",
         "bottom","The bottom is made of fouly wood",
         "stairway","The stairway is made of granite and leads down",
        });
     }
  }
