inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){

  short_desc = "Remnants of humanity lie all around";
  long_desc =
"The smell of rotting flesh and tissue clings to the walls of the cave.  "+
"Lying all along the walls are the remnants of human skeletons and old "+
"rusted battle gear.  The floor is clear in the center but the floor is "+
"an odd brown color.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room202","southeast",
    sr+"/room204","west",
  });
  items = ({
    "remnants",
    "Bits and pieces of human flesh cling to the skeletons",
    "skeletons",
    "These skeletons are all that is left of human",
    "gear",
    "This battle gear is rusted and barely recognizable",
    "walls",
    "The wall is covered with red stains",
  });
    clone_list = ({ 1, 3, "monster", sm+"/goblin.c", 0 });   
    ::reset(arg);
    replace_program("room/room");
}
