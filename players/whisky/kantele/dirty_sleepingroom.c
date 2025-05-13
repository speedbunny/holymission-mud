
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
    if (flag == 0)
    {
      dest_dir =
      ({
        PATH+"mechanic_room" , "west",
      });

      short_desc = "A dirty sleeping room";
      long_desc = BS(
        "A dirty sleeping room, a single dirty bed stands in one corner. " +
        "It just looks as people had sex in it.");
      items =
      ({
        "bed","The bed is dirty , there are some sticky spots on it",
        "walls","The walls are made of red bricks",
        "ceiling","The ceiling is made of red bricks",
        "bottom","The bottom is made of oak",
       });
    }
}
