
/* cave 9 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
        CM("snake");
        CM("snake");
        CM("snake");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "A lit, hidden passage";
        long_desc = BS(
        "You are standing kneedeep in the water of a hidden, dirty "+
        "passage in the volcano. The stone walls are covered "+
        "with fouly moss and it's really stinging here. The cave "+
        "leads back to the east and further to the north where you "+
        "can see some dim light coming from.");
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
         PATH+"cave8","east",
         PATH+"cave10","north",
        });
     }
}

void init()
{
     ::init();
}



