
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
    if (flag == 0)
    {
      dest_dir = 
      ({
         PATH+"dirty_stairway","north",
         PATH+"dirty_temple","south",
      });

       short_desc = "You are in a small room";
       long_desc = BS(
       "You are in a small room, there is a stairway to the north "+
       "and some sort of temple to the south."); 
       items =
       ({
       "walls","The walls are made of red bricks",
       "ceiling","The ceiling is made of red bricks",
       "bottom","The bottom is made of fouly oak wood",
       });
     }
}

