inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "Here the road comes to an elbow.  It continues north and east.  The "+
    "sounds of magic chanting comes from the west.  To the south the beach "+
    "makes way to the ocean.  The sounds of a crowd come from the east.\n";
  set_light(1);
  items = ({
    "beach",
    "The Towpath public beach",
    "ocean",
    "The Pansiac Ocean",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
  });
  dest_dir = ({
    br+"/tr-11","north",
    br+"/tr-13","east",
    br+"/tran","west",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg); 
  replace_program("room/room");
}
