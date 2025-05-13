


/* living_room */

inherit "/room/room";
#include "defs.h"

object demon;

void reset(int flag)
{
     ::reset(flag);
     if (!present("household demon",this_object())) 
         CM("demon");
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Inside Kantele's livingroom";
         long_desc = BS(
         "You are inside Kantele's livingroom. Is tasteful furnished. "+
         "An exit leads west inot the hall or south to a bar.\n");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
         });
         dest_dir =
         ({
             PATH+"inner_hall","west",
             PATH+"bar","south",
         });
      }
}

