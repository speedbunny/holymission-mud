 

/* upper_hall */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "In the upper hall";
         long_desc = BS(
         "You are in the hall on the second floor of Kantele's castle. "+
         "To the north you can see the exit leading to the roof" +
         "To the south you can see the stairway.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "roof","You can see the roof of the castle",
            "stairway","You can see a wooden stairway to the south",
         });
         dest_dir =
         ({
             PATH+"on_roof","north",
             PATH+"lab","west",
             PATH+"small_room","east",
             PATH+"stairway_up","south",
         });
      }
}

