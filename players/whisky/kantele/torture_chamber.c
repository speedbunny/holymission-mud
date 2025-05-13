

/* torture chamber */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "In the torture chamber";
         long_desc = BS(
         "You have entered the torture chamber of Kanteles castle. "+
         "the only exit is east into the guardroom. You " +
         "can see a well used stretch bench and an ironmaiden.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "ironmaiden","It looks out of use",
         });
         dest_dir =
         ({
             PATH+"guard_room","east",
         });
      }
}

