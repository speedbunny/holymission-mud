
/* cave 5 */

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
        "You are crawling and swimming in the water of a hidden "+
        "stinking passage. There is some water at the bottom "+
        "reaching up to your hips. The stone walls are covered "+
        "with fouly moss and it's really stinking here. The cave "+
        "is leading back to the south, but to the north you are "+
        "blocked by 'a big heap of human skulls'.");
        items = 
        ({
         "bottom","There is kneedeep water covering the bottom",
         "ground","There is kneedeep water covering the bottom",
         "water","The water is dirty and stinging badly",
         "walls","They are made of massive granit",
         "moss","Green stinking moss is covering the walls",
         "heap","A big distgusting heap of human skulls,\n"+
                "but on its top you see a small opening.\n"+
                "Maybe you can 'climb' it up",
         "skills","A big distgusting heap of human skulls,\n"+
                "but on its top you see a small opening.\n"+
                "Maybe you can 'climb' it up",
        });
        dest_dir = 
        ({
         PATH+"cave4","south",
        });
     }
}

void init()
{
     add_action("do_climb","climb");
     ::init();
}

int do_climb(string arg)
{
   if (!arg)
       return 0;
   else if (strstr(arg,"heap",0)!=-1)
   {
       this_player()->move_player(
       "climbing up the skulls#players/whisky/island/room/caves/room/cave6");
       return 1;
   }
   return 0;
}


