inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {

  short_desc = "Town road";
  long_desc =
    "The road here has a mural depicting an elf and a dwarf attacking a "+
    "massive orc painted on it.  Above your head is a plethora of herbs "+
    "hanging from ropes hung between two buildings.  The smell of "+
    "rosemary and thyme hangs in the air.\n";
  set_light(1);
  items = ({
    "buildings",
    "Some of Towpath's finest shops",
    "ropes",
    "They are in place so that herbs can be dried off of them",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "brick",
    "The road is half brick",
    "mural",
    "A beautiful painting",
    "herbs"
    "Many different types of herbs",
  });
  dest_dir = ({
    br+"/tr-6","east",
    br+"/tr-8","west",
    br+"/gen_store","south",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  replace_program("room/room");
}
