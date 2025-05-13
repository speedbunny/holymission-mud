
/* cave 1 */

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
        "You are sneaking through the crack in the cave into "+
        "a hidden passage. There is some water at the bottom "+
        "reaching up to your knees. The stone walls are covered "+
        "with fouly moss and it's really stinging here. The cave "+
        "is leading further to the north and back through the crack.");
        items = 
        ({
         "bottom","There is kneedeep water covering the bottom",
         "ground","There is kneedeep water covering the bottom",
         "water","The water is dirty and stinging badly",
         "walls","They are made of massive granit",
         "moss","Green stinking moss is covering the walls",
         "crack","It's a small crack, but maybe with some attemt\n",
                 "you can 'enter' it",
        });
        dest_dir = 
        ({
         PATH+"cave2","north",
        });
     }
}

void init()
{
     add_action("do_enter","enter");
     ::init();
}

int do_enter(string arg)
{
    if (arg!="crack")
        return 0;
    this_player()->move_player(
    "squeezing through a crack#/players/whisky/island/room/gnome25");
    return 1;
}

