inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "To the west the town wall bows out to make room for the Towpath Inn. "+
    "A massive archway serves as the door into the inn.  From the east "+
    "comes the smell of coffee beans and the murmur of hushed voices.\n";
  set_light(1);
  items = ({
    "wall",
    "It bows out to make room for the inn",
    "inn",
    "The Townpath inn is currently closed for renovations",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "archway",
    "The entrance to the Towpath Inn",
  });

  dest_dir = ({
    br+"/tr-12","south",
    br+"/tr-10","north",
    // br+"/inn","west",
    br+"/coffee","east",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  replace_program("room/room");
}
