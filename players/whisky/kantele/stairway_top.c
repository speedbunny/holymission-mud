
inherit "/room/room";
#include "defs.h"


void reset(int flag)
{
   if (flag == 0)
   {
    short_desc = "You are on the upper landing";
    long_desc = BS(
          "You are on a landing in the stairway. This place gives you "+
          "a bad feeling. You can hear the hissing of snakes near you. "+
          "Maybe it's a good decission to go the stairway back ?");
     items =
     ({
      "bottom","The bottom is made of fouly wood",
      "walls","Te walls are made of red bricks",
      "ceiling","The ceiling is made of red bricks",
      "stairway","The stairway is leading up and down",
     });
     dest_dir =
     ({
     PATH+"stairway_up","down",
     PATH+"snake_pit","up",
     });
    }
 }

int move(string arg)
{
    if (!arg)
         arg=query_verb();

    if (arg=="up")
    {
       write("\n***** You are falling *****\n\n");
       write("***** You are falling *****\n\n");
       write("***** You are falling *****\n\n");
       write("***** You are falling *****\n\n");
       write("***** You are falling *****\n\n");
    }
   return ::move(arg);
}
