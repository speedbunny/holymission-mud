

/* on_roof */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "On the Roof";
         long_desc = BS(
         "You are standing on the roof of Kantele's castle "+
         "If you wouldn't know you could swear that the building "+
         "to the north looks like a stable. You can think you " +
         "can smell sulphur here.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "building","The building to the north looks like a stable",
         });
         dest_dir =
         ({
             PATH+"stable","north",
             PATH+"upper_hall","south",
         });
      }
}

