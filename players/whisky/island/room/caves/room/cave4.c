
/* cave 4 */

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
        "You are standing kneedeep in the water of a hidden passage "+
        "in the volcano. There is some water at the bottom "+
        "reaching up to your knees. The stone walls are covered "+
        "with fouly moss and it's really stinging here. The cave is "+
        "leading to the north and back to the east.");
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
         PATH+"cave5","north",
         PATH+"cave3","east",
        });
     }
}

void init()
{
     ::init();
}


