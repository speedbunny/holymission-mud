inherit "/players/tamina/teds/inherits/shop";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);

  set_light(1);
  short_desc = "The Golden Fleece Store";
  long_desc = 
    "You are in the Golden Fleece Shop and Emporium. \n"+
    "Only the finest goods are sold here, so shop away!\n"+
    "You can look at what is on offer, by typing <list>\n";

  store = "/room/store";

  dest_dir = ({ 
    TPATH + "road2", "north" 
  });

  keeper = "Kay";
}
