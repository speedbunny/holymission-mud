inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Orc training room";
  long_desc =
"Several training dummies sit in the center of the room.  Crude "+
"weights sit on a rack in the corner.  A bag of flour hangs from "+
"the ceiling on a rope.  The room smells overpoweringly of sweat.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room610","northwest",
    sr+"/room608","southeast",
  });
  items =({
    "dummies",
    "A training dummy with maces for hands",
    "weights",
    "Crude weights that sit on a rack",
    "bag",
    "A crude punching bag",
  });
  clone_list = ({ 
       1, 2, "monster", sm+"/orc_guard.c", 0,
       2, 1, "mon2", sm+"/orc_taskmaster.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
