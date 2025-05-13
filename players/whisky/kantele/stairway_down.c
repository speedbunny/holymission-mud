
inherit "/room/room";
#include "defs.h"

#define HAUNT present("haunt",this_object())

void reset(int flag)
{
    if (!HAUNT)
         CM("haunt");
    if (flag == 0)
    {
      dest_dir =
      ({
        PATH+"stairway.c","up",
        PATH+"cellar_west","west",
        PATH+"cellar_east","east",
      });

       short_desc = "At the bottom of a stairway";
       long_desc = BS(
         "You are at the bottom of the stairway, the stairway goes up " +
         "and you can go further into the cellar to the west.");
       items =
       ({
        "bottom","The bottom is made of oak wood",
        "walls","The walls are made of red bricks",
        "ceiling","The ceiling is made of red bricks",
        "stairway","The wooden stairway is leading up",
        "cellar","There is a cellar to the west",
       });
     }
}

int move(string arg)
{
    object haunt;

    haunt = HAUNT;

    if (!arg)
         arg = query_verb();

    if (arg == "west" && haunt && living(haunt))
    {
        write("But the Ghostly Haunt stands in the way.\n");
        return 1;
    }
    return ::move(arg);
}

