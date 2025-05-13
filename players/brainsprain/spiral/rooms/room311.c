inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark hall";
  long_desc =
"The walls of this hallway are glassy smooth.  An old, red carpet runs down "+
"the center of the room and disappears into the next room.  Huge stalagtites.  "+
"hang from the ceiling.  A draft blows through the rooms and whistles "+
"between the stalagtites.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room310","north",
    sr+"/room312","south",
  });
  items = ({
    "stalagtites",
    "Huge stalagtites which have been carved to resemble screaming faces",
    "carpet",
    "A red carpet of welcome, how ironic",
      });
::reset(arg);
    replace_program("room/room");
}

