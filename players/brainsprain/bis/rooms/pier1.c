inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
 
  short_desc = "Town pier";
  long_desc =
    "A wooden deck extends from the pier out into the ocean.  The pier is "+
    "crowded with sailors going ashore for their leave and people carrying "+
    "various packages to their destinations.  The dock continues to the south.\n";
  set_light(1);
  dest_dir = ({
    br+"/tr-16","north",
    br+"/pier2","south",
  });
  items = ({
    "people",
    "Passengers newly coming ashore from an ocean voyage",
    "packages",
    "They contain the possessions of the ships passengers",
    "deck",
    "A fine mahogany deck on the dock",
    "pier",
    "The loading pier for Towpath",
    "sailors",
    "Brawny men with eye-patches",
    "dock",
    "The dock where all the boats rest",
  });
  ::reset(arg);
  replace_program("room/room");
}
