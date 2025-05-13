inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
  
  short_desc = "Towpath town road";
  long_desc = 
    "This road leads into Towpath, the center of trade for the Bismarck "+
    "Empire.  People hurry back and forth on the road as they go about "+
    "their business.  Deep ruts are worn into the path from the constant "+
    "traffic.\n";
  items = ({
    "traffic",
    "People hurry about their business",
    "path",
    "The main road leading into Towpath",
    "people",
    "People hurry about their business",
    "road",
    "The main road leading into Towpath",
    "towpath",
    "The nearest town",
    "bismarck",
    "The family that rules this area",
    "empire",
    "The Bismarck Empire",
    "ruts",
    "Left by carts that have traveled over this path",
  });
  set_light(1);
  dest_dir = ({
    br+"/tr-2","west",
    br+"/mountainside","east",
  });
  ::reset(arg); 
  replace_program("room/room");
}
