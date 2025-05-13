
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
    if (flag == 0)
    {
      dest_dir =
      ({
           PATH+"kitiaras_anteroom","north",
           PATH+"snake_room","east",
           PATH+"kitiaras_innerhall","south",
       });

       short_desc = "You are on a crossing";
       long_desc = BS(
           "You are in a crossing, a passage goes north/south and an exit "+
           "leads east.");
       items = ({
           "passage","The passage leads north/south",
           "exit","The exit leads east",
           "bottom","Its an old oak wooden bottom",
           "walls","The walls are made of bricks",
           "ceiling","The ceiling is dusty and made of bricks",
           });
     }
}

