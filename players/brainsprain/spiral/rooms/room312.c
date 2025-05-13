inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark hall";
  long_desc =
"The northern half of the room has a red carpet on the floor.  The walls "+
"to the north are glassy smooth.  The other half of the room is looks "+
"as if it was freshly blasted from the rock.  The end of the carpet is "+
"torn.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room311","north",
    sr+"/room313","southeast",
  });
  items = ({
    "carpet",
    "A red carpet of welcome, how ironic",
      });
    clone_list = ({ 
       1, 3, "monster", sm+"/goblin.c", 0,
    });   
  ::reset(arg);
    replace_program("room/room");
}

