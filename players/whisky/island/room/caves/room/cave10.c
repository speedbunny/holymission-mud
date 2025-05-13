
/* cave 10 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "A lit, hidden passage";
        long_desc = BS(
        "You are standing in a narrow part of the hidden passage, "+
        "deep inside the volcano. Some beams of light come from "+
        "an opening to the north. The bottom is still wet, dirty "+ 
        "and mosscovered. The cave leads towards an opening to "+
        "the north and back to the south. ");
        items = 
        ({
         "bottom","There is kneedeep water covering the bottom",
         "ground","There is kneedeep water covering the bottom",
         "water","The water is dirty and stinging badly",
         "walls","They are made of massive granit",
         "moss","Green stinking moss is covering the walls",
         "opening","There is some dim light coming from an opening",
        });
        dest_dir = 
        ({
         PATH+"cave9","south",
         PATH+"cave11","north",
        });
     }
}

void init()
{
     ::init();
}



