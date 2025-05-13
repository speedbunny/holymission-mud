inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A long hallway";
  long_desc =
"The hall curves slightly to the left.  Pieces of quartz make the "+
"walls shimmer with your torchlight.  Several archaic symbols are "+
"drawn on the floor.  Water drips from the ceiling and lands in "+
"the center of the room.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room607","south",
    sr+"/room609","northwest",
  });
  items =({
    "symbols",
    "a pentagram and a circle with a feather in it",
  });
    clone_list = ({ 
       1, 1, "monster", sm+"/orc_witchdoctor.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
