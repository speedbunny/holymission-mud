inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){

  short_desc = "Goblin Warrens";
  long_desc =
"Straw mats lay all over this room.  Several of the mats have been recently "+
"used.  This area appears to be the communal area for some of the goblins "+
"to sleep.  The overpowering scent of sweat and urine fills the air.  A "+
"crude pile of clothing sits festering in the middle of the room.\n\n";
  set_light(1);
  dest_dir = ({
    sr+"/room206","northeast",
    sr+"/room208","south",
  });
  items = ({
    "straw",
    "Dirty straw has been woven together to form crude sleeping mats",
    "wall",
    "The walls seem to have been recently chiseled from the pre-existing cave",
    "mat",
    "A pile of straw lying along the wall",
    "clothing",
    "A pile of cloths that desperately need cleaning",
  });
    clone_list = ({ 1, 4, "monster", sm+"/goblin.c", 0 });   
    ::reset(arg);
    replace_program("room/room");
}
