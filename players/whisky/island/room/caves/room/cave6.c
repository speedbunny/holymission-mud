
/* cave 6 */

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
        "You are crawling and swimming in the dirty water of "+
        "a hidden passage. There is some water at the bottom "+
        "reaching up to your knees. The stone walls are covered "+
        "with fouly moss and it's really stinging here. The cave "+
        "leads further back to the north, and to the south you see a "+
        "small opening and a huge 'heap of human skulls'.");
        items = 
        ({
         "bottom","There is kneedeep water covering the bottom",
         "ground","There is kneedeep water covering the bottom",
         "water","The water is dirty and stinging badly",
         "walls","They are made of massive granit",
         "moss","Green stinking moss is covering the walls",
         "heap","A big distgusting heap of human skulls,\n"+
                "Maybe you can 'slide' it down",
         "skills","A big distgusting heap of human skulls,\n"+
                "Maybe you can 'slide' it down",
        });
        dest_dir = 
        ({
         PATH+"cave7","north",
        });
     }
}

void init()
{
     add_action("do_slide","slide");
     add_action("do_slide","south");
     ::init();
}

int do_slide()
{
       write("Uiiiiii you slide down the heap of skulls.\n"); 
       this_player()->move_player(
       "sliding down the skulls#players/whisky/island/room/caves/room/cave5");
       return 1;
}


