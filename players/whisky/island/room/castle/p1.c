
/* p1 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "On the Cliffs";
         long_desc = BS(
         "You are standing big black cliffs to the west you see "+
         "small stone stairs leading into a dark cave. To the north "+
         "you can see a small opening in the cliffs, where you can "+
         "make your way further into this stone labyrinth."); 
         items =
         ({
          "cliffs","Big black cliffs",
          "cave","A dark cave leading into the mountain",
          "opening","There is a small opening in the cliffs",
         });
         dest_dir =
         ({
             PATH+"p3","north",
             "/players/whisky/island/room/caves/room/ci24","up",
         });
      }
}

    
    

