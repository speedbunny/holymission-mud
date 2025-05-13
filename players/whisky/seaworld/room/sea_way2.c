

inherit "room/room";
#include "../seaworld2.h"


void reset(int flag) 
{

/*
       if (!find_living("trans_dragon"))
            CM("dragon");
*/

 if (flag == 0)
 {
  CO("sign");
  set_light(1);
  short_desc = "On a stony path";
  long_desc = BS( 
    "You are now walking on a stony path. To the south you can "+
    "see the big fence of beautiful garden and to the north you "+
    "can see the entrance of an inn.");
  
  dest_dir = 
    ({
    "/players/whisky/seaworld/room/path_end","east",
    "/players/whisky/seaworld/room/sea_bar","north",
    "/players/whisky/seaworld/room/sea_way","west" 
    });

   items = 
   ({
    "forest","You see a lot of big spruces",
    "stonewall","Maybe the way to the sea but now unpossible to pass",
    "fence","You see a big brown garden fence",
    "bottom","You see a stony bottom"
    });
  }
}
   
