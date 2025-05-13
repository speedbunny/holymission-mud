
/* p8 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "Next to a small Path";
         long_desc = BS(
         "You are crawling between big black cliffs. To the south "+
         "see a small opening in the cliffs. To the north you can "+
         "see a big crack in a cliff where you can squeeze yourself "+
         "up to the beginning of a small nature path.");
         items =
         ({
          "cliffs","Big black cliffs",
          "opening","There is a small opening in the cliffs",
          "crack","A big crack in the cliff, ending at the\n"+
                  "beginning of a small nature path.",
          "path","A small nature path, winding itself up a mountain",
         });
         dest_dir =
         ({
             PATH+"p9","up",
             PATH+"p6","south",
         });
      }
}

    
    

