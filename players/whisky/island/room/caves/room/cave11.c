
/* cave 11 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(1);
        short_desc = "At an opening";
        long_desc = BS(
        "You are standing next to a big opening, leading out "+
        "into a green grassy prarie. Beams of sunlight burn "+
        "your face and big walls block your way to the east "+
        "and west. The passage leads back to the south.");
        items = 
        ({
         "bottom","There is kneedeep water covering the bottom",
         "ground","There is kneedeep water covering the bottom",
         "water","The water is dirty and stinging badly",
         "walls","They are made of massive granit",
         "moss","Green stinking moss is covering the walls",
         "opening","You see a grassy prarie through the opening",
        });
        dest_dir = 
        ({
         PATH+"cave10","south",
         PATH+"prarie1","up",
        });
     }
}

void init()
{
     ::init();
}



