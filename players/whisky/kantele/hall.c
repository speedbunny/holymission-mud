
/* hall */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc =
         long_desc = BS(
         "You are standing at the entrance of Kantele's castle "+
         "To the south a corridor leads further deeper into the "+
         "castle. To the north you can leave the castle over an "+
         "open drawbridge.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "drawbridge","A strong wooden drawbridge",
         });
         dest_dir =
         ({
             PATH+"inner_hall","south",
             "/players/whisky/island/room/castle/cp10","north",
         });
      }
}

    
