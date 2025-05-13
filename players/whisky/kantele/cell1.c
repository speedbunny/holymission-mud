
 

/* cell1 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (!present("solar",this_object())) 
         CM("solar");
     if (flag == 0)
     {
         set_light(0);
         short_desc =
         long_desc = BS(
         "You have entered a small, dirty cell. The bottom is "+
         "stinking like bred wood and some bricks on the wall "+
         "are dusry and broken.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling is made if red bricks",
            "walls","The walls are made of red bricks",
         });
         dest_dir =
         ({
             PATH+"dungeon_corridor","north",
         });
      }
}


