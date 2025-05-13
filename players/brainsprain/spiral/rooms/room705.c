inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "An aqueduct";
  long_desc =
"The aqueduct continues in this room, widening as the water pressure "+
"rises.  The aqueduct disappears into the western wall. Several broken "+
"water vessels lie scattered about the room.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room706","southeast",
    sr+"/room704","north",
  });
items = ({
  "aqueduct",
  "A wooden trough",
  "vessels",
  "Broken water vessels",
      });
  clone_list = ({ 
       1, 1, "monster", sm+"/orc_witchdoctor.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
