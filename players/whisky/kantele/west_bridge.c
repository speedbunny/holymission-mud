

/* west bridge */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "In a Hall";
         long_desc = BS(
         "You have entered a long, wide hall in Kantele's castle. "+
         "The exits are leading off in every direction. " +
         "To the east you can see a rotten wooden bridge.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
         });
         dest_dir =
         ({
             PATH+"guard_room","west",
             PATH+"on_bridge","east",
         });
      }
}

    
