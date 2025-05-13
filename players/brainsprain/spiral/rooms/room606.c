inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A long hallway";
  long_desc =
"Pieces of rotting flesh lie all over the room.  Several human skulls "+
"lie in the corner of the room.  The walls are covered in gore.  There "+
"are even pieces of flesh on the ceiling.  Obviously some battle has "+
"been fought here.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room605","southwest",
    sr+"/room607","northeast",
  });
  items =({
    "flesh",
    "Hunks of rotting flesh",
    "skulls",
    "Several caved in skulls",
  });
    clone_list = ({ 
       1, 2, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}

