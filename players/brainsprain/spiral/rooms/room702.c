inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Tapestry Room";
  long_desc =
"A tattered tapestry covers the entire northern wall of this room.  The "+
"tapestry depicts a battle between the orcs and a clan of dwarves.  "+
"The rest of the room is filled with what appear to be relics of the battle.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room701","east",
    sr+"/room703","southwest",
  });
  items =({
    "relics",
    "A shattered dwarven helmet, firmly bolted to the ground",
    "tapestry",
    "It tells the story of the orc/dwarf wars",
  });
  clone_list = ({ 
       1, 2, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
