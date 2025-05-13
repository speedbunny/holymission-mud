inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Goblin Furnace";
  long_desc =
"Heat rolls off of a huge furnace sitting along the western wall of this "+
"room. A large pile of coal sits next to the furnace and a shovel sticks "+
"out of the coal.  There is a door along the southwestern wall of the room\n";
    set_light(1);
    dest_dir = ({
    sr+"/room301","southwest",
    sr+"/room303","north",
  });
  items = ({
    "coal",
    "A large pile of coal",
    "furnace",
    "A glowing red furnace",
    "door",
    "A small red door on the northeastern wall",
    "shovel",
    "The handle of a coal shovel",
  });
  ::reset(arg);
    replace_program("room/room");
}

