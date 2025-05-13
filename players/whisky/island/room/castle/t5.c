
/* t5 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Before a bend in the tunnel";
         long_desc = 
         BS(
         "You are sneaking inside a long dark tunnel. You are covered "+
         "by deep darkness. All around you there are big black stones. "+ 
         "A cold breeze of air streams through the tunnel. To the north "+
         "you rather see the outlines of a stonewall, just like you "+
         "are next the end of this tunnel.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t6","north",
             PATH+"t4","south",
         });
      }
      if (!present("cave bear",this_object()))
           CM("cave_bear");
}

int move(string arg)
{
   object bear;

   bear = present("cave bear",this_object());

   if (!arg)
       arg = query_verb();

   if (arg=="north" && bear && living(bear))
   {
      write("The body of the big cave bear blocks your way !\n");
      return 1;
   }
   return ::move(arg);
}


   
    
    

