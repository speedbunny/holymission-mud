inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "To the north is the town room where townspeople or visitors can get "+
    "together, leave notes, or have a town meeting.  To the south a pier "+
    "extends into the ocean.  To the east the road curves northward.\n";
  set_light(1);
  items = ({
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "pier",
    "The Towpath Town pier",
    "ocean",
    "The Pansiac Ocean",
  });
  dest_dir = ({
    br+"/town_room","north",
    br+"/tr-15","west",
    br+"/tr-17","east",
    br+"/pier1","south",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  
  replace_program("room/room");
}
