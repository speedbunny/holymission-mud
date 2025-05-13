inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "Here the road curves to the north and to the west.  To the east is "+
    "a huge building.  Over the door is a sign declaring the building "+
    "to be the Towpath Archive.  High overhead comes the scream of an "+
    "eagle.\n";
  set_light(1);
  items = ({
    "door",
    "The door to the Towpath Archive",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "building",
    "The Towpath archive",
    "sign",
    "It reads:  Towpath Archive",
    "eagle",
    "A golden eagle",
  });
  dest_dir = ({
    br+"/tr-18","north",
    br+"/tr-16","west",
    br+"/archive","east",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  replace_program("room/room");
}
