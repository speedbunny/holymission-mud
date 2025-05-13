inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "The road here is filled with people.  People hustle to and fro rushing "+
    "and pushing to get to their destination.  People of every race wander "+
    "through town looking for the best deal.  To the east the town wall "+
    "rises up and to the west is the wall of a building.\n";
  set_light(1);
  items = ({
    "people",
    "The citizens of Towpath",
    "town",
    "Towpath",
    "wall",
    "The protective wall surrounding Towpath",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "people",
    "People of many different races",
    "building",
    "The wall of the town hall",
  });
  dest_dir = ({
    br+"/tr-3","north",
    br+"/tr-17","south",
  });
  rnd = random(6);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg); 
  replace_program("room/room");
}
