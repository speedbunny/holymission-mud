inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "The deafening sound of a hammer striking an anvil comes from the "+
    "building to the south.  To the north, stairs lead up a cliff. "+
    "However, the entrance is boarded off.  The road continues east "+
    "and west.\n";
  set_light(1);
  items = ({
    "entrance",
    "This is the entrance to the Towpath development project.  "+
    "Future additions to the town will be added here",
    "building",
    "The Towpath Armoury",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "brick",
    "The road is half brick",
    "stairs",
    "Stairs leading to the service entrance to Castle Bismarck",
    "cliff",
    "A steep cliff, the only way up it is the stairs",
  });
  dest_dir = ({
    br+"/tr-5","east",
    br+"/tr-7","west",
    br+"/armoury","south",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg); 
  replace_program("room/room");
}
