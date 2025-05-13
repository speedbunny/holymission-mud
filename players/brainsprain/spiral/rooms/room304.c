inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Room full of paintings";
  long_desc =
"This huge tunnel is covered in paintings.  Crude drawings of goblin's "+
"in their daily tasks are on the walls.  Several of them depict the "+
"slaying of various races of creatures.  The main color used is a curious "+
"rust-brown.  What could it be?\n";
    set_light(0);
    dest_dir = ({
    sr+"/room303","south",
    sr+"/room305","northwest",
  });
  items = ({
    "paintings",
    "They are done in blood",
  });
  ::reset(arg);
    replace_program("room/room");
}
