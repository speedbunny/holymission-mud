inherit "/players/blaarg/stuff/shop1";

#include "/players/blaarg/defs1.h"

void reset(int arg) 
{
  ::reset(arg);

  set_light(1);
  short_desc = "Uykio's Shop";
  long_desc = 
    "You are in Uykio's Shop. Anything and Everything is\n"+
    "sold here, so feel free to look around!\n"+
    "You can look at what is on offer, by typing <list>\n";

  store = "/room/store";

  dest_dir = ({ 
    AROOMS+"road7", "east",
    AROOMS+"uhouse","west",
    AROOMS+"roadb1","north",
  });

  keeper = "Uykio";
}
