
/* cave 3 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "A hidden passage";
        long_desc = BS(
        "You are standing in a wet, hidden passage deep inside "+
        "the vocano. There is some water at the bottom "+
        "reaching up to your knees. The stone walls are covered "+
        "with fouly moss and it's really stinging here. The cave is "+
        "leading back to the south and bends to the west.");
        items = 
        ({
         "bottom","There is kneedeep water covering the bottom",
         "ground","There is kneedeep water covering the bottom",
         "water","The water is dirty and stinging badly",
         "walls","They are made of massive granit",
         "moss","Green stinking moss is covering the walls",
        });
        dest_dir = 
        ({
         PATH+"cave4","west",
         PATH+"cave2","south",
        });
     }
}

void init()
{
     ::init();
}


