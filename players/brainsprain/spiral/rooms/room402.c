inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A tunnel with a low ceiling";
  long_desc =
"The ceiling of the cave is so low that you have to stoop to pass through "+
"it.  The walls are circular and look like they were bored into the hillside "+
"A thick pillar rises up in the center of the room.  There is a hole in "+
"the center of the pillar.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room401","west",
    sr+"/room403","northeast",
  });
  items = ({
    "hole",
    "The hole is smooth and about one foot in diameter",
    "pillar",
    "A stalagtite and a stalacmite have come together",
  });
    clone_list = ({ 
       1, 1, "monster", sm+"/goblin_fighter.c", 0,
    });   
  ::reset(arg);
    replace_program("room/room");
}
