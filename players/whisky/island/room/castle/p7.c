
/* p7 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "Between the Cliffs";
         long_desc = BS(
         "You are crawling between big black cliffs. To the south "+
         "and west you can see a small opening in the cliffs, where "+
         "you can make your way further into this stone labyrinth."); 
         items =
         ({
          "cliffs","Big black cliffs",
          "opening","There is a small opening in the cliffs",
         });
         dest_dir =
         ({
             PATH+"p4","south",
             PATH+"p6","west",
         });
      }
}

    
    

