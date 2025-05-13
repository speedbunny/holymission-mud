inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){

  short_desc = "Hand hewn cave walls";
  long_desc =
"The walls of the cave have lost their natural look.  Long scores mark the "+
"walls here and there.  Large sections of the walls seem to have been burnt "+
"  by an incredibly hot fire.  The smell of sulfur hangs in the air.\n";
  set_light(1);
  dest_dir = ({
    sr+"/room207","north",
    sr+"/room209","south",
  });
  items = ({
    "walls",
"Sections of the wall are scored and others appear to have melted into shape",
  });
    clone_list = ({ 1, 2, "monster", sm+"/goblin_fighter.c", 0 });   
    ::reset(arg);
    replace_program("room/room");
 }
