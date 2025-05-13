

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
   if (flag == 0)
   {
      dest_dir =
      ({
           PATH+"stairway","down",
           PATH+"stairway_top","up",
           PATH+"upper_hall","north",
      });

       short_desc = "You are at a landing in the stairway";
       long_desc = BS(
       "You are on a landing in the stairway. The stairway continues up " +
       "and down, you can go north into the hall. On the east wall you " +
       "can see a large painting of Kantele and her sister on a dragon" +
       "hunt they had on one of the outer planes.");
       items = 
       ({
         "painting","The large painting covers the wall "+
                    "from ceiling to the floor\n"+
         "It is fastened to the wall with some large nails and it looks\n"+
         "almost impossible to get loose",
         "walls","The walls are made of red bricks",
         "ceiling","The ceiling is made of red bricks",
         "bottom","The bottom is oak wooden",
        });
      }
  }
