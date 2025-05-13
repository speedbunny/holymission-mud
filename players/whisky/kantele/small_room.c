

/* small_room */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Inside a dusty room, with a pentagram";
         long_desc = BS(
         "You are inside a small, dusty room in Kantele's castle "+
         "In the middle of the room you can see a pentagram chalked "+
         "up in the dirt. You can leave the room to the west.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
         });
         dest_dir =
         ({
             PATH+"upper_hall","west",
         });
      }
}
