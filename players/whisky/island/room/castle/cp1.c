
/* cp1 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "Next to a tunnel";
         long_desc = SIGHT+BS(
         "You are wandering on the steep path. To the south you can "+
         "see the entrance to a long dark tunnel. In the far distance "+
         "you can see a dark building one the western side of the "+
         "mountain. Far to the north you can see the island ezo."); 
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "distance","In the near distance you can see a ruin",
            "ruin","An old looking, wrecked castle",
            "castle","An old looking, wrecked castle",
            "ezo","To the north you can see the island of ezo",
         });
         dest_dir =
         ({
             PATH+"t10","south",
             PATH+"cp2","north",
         });
      }
}

int move(string arg)
{
   if (!arg)
        arg = query_verb();

   if (arg=="south")
       write("You slide down a big rock.\n");
   return ::move(arg);
}

  
    
    

