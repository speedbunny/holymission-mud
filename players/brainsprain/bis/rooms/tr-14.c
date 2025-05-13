inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "The road here is little more that a well-worn, dirt footpath.  Debris "+
    "and garbage litter the street.  However, directly to the north is "+
    "a blindingly white building.  To the south the beach is covered "+
    "in seaweed and flotsam and jetsam.\n";
  set_light(1);
  items = ({
    "jetsam",
    "Pieces of debris on the beach",
    "beach",
    "The Towpath public beach",
    "footpath",
    "The main road in Towpath",
    "garbage",
    "Big piles of garbage",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "debris",
    "Chunks of garbage",
    "flotsam",
    "Pieces of a a crushed boat",
    "building",
    "A magic shop",
  });
  dest_dir = ({
    br+"/tr-13","west",
    br+"/tr-15","east",
    br+"/mage","north",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg); 
  replace_program("room/room");
}
