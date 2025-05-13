
/* cellar_passage */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(1);
        short_desc = "A dimly lit hallway";
        long_desc = BS(
        "You are standing in a small dark hallway. Moonlight coming "+
        "from a small window illuminate the hallway, so that you can "+
        "see some candedliers with long red torches fixed to the wall.");

        items = 
        ({
           "window","A real small opening, too small to enter",
           "candeliers","Long red torches are fixed to the candeliers",
           "torches","They are beautiful, but you cant reach them",
        });
   
        dest_dir =
        ({
            PATH+"cellar_east","south",
            PATH+"cellar_passage1","north",
        });
     }
}

 
