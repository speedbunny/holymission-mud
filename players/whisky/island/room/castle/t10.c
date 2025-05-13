
/* t9 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Entrance of a tunnel";
         long_desc = 
         BS(
         "You are standing on the entrance to a big dark tunnel. "+
         "To the north you can see a big heap of rocks blocking you "+
         "way further. To the south the way leads back into the "+
         "dark cave.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "stones","A big heap of rocks, but they look climbable",
            "stones","There are black stones all around you",
         });
         dest_dir =
         ({
             PATH+"t9","south",
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
     if (arg=="rocks" || arg=="stones" || arg=="heap")
     {
        write("You crawl up the rocks.\n");
        this_player()->move_player("crawling up the rocks#"+PATH+"cp1");
        return 1;
    }
   return 0;
}


