
inherit "/room/room";

#include "defs.h"

void reset(int flag) 
{
    ::reset(flag);
    if (flag == 0)
    {
       short_desc = "A small dark hall";
       long_desc = BS(
          "You are in a small dark hall, a dirty passage leads  "+
          "east, you can see some light to the north.");
       items =
       ({
        "bottom","The bottom is made of wood",
        "walls","The walls are made of red bricks",
        "ceiling","The ceiling is made of dusty red bricks",
        "passage","The dark passage leads south",
        });
       dest_dir =
       ({
               PATH+"cellar_west","north",
       });
    }
}

void init()
{
   ::init();
   (PATH+"kitiaras_anteroom")->is_door_here();
}



