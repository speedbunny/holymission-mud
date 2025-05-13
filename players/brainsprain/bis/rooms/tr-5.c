inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "The road here widens to accomodate the massive amount of traffic. "+
    "To the south is a huge stone structure with a cross on top.  On "+
    "this side of the structure, the wall is made of huge stones cemented "+
    "together.\n";
  set_light(1);
  items = ({
    "cross",
    "A religious symbol",
    "stones",
    "Massive stones cemented together to form the church",
    "traffic",
    "People surge through the area on their way about their business",
    "people",
    "Citizens and visitors of Towpath",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "brick",
    "The road is half brick",
    "structure",
    "A church",
  });
  dest_dir = ({
    br+"/tr-4","east",
    br+"/tr-6","west",
  });
  rnd = 5+random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  replace_program("room/room");
}
