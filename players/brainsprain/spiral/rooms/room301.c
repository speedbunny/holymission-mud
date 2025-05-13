inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "The bottom of the staircase";
  long_desc =
"A set of stairs heads upwards here.  To the northeast lies a slightly ajar "+
"door.  A breeze wafts into the room from that direction as well as light.  "+
"Beads of moisture stand out on the surface of the walls and glisten in the "+
"torch light.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room214","up",
    sr+"/room302","northeast",
  });
  items = ({
    "stairs",
    "Rough hewn stairs leading up to the second level of caves",
    "door",
    "A small red door on the northeastern wall",
  });
    ::reset(arg);
    replace_program("room/room");
}

