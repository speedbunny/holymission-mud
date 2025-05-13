inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A stairwell";
  long_desc =
"A set of stairs wind down into the next floor of the cavern.  The room "+
"is bubble shaped and glassy smooth.  The northwestern wall looks like "+
"someone blasted it.  The floor is covered in tiny shards of granite.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room312","northwest",
    sr+"/room401","down",
  });
    clone_list = ({ 
       1, 1, "monster", sm+"/goblin_mystic.c", 0,
    });   
  ::reset(arg);
    replace_program("room/room");
}
