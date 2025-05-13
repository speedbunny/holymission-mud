inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){

  short_desc = "A dark hall";
  long_desc =
"The walls of this room are hard to make out because they are so far "+
"apart.  The floor is uneven here and hard to walk on.  A faint breeze "+
"blows through the room from the north.  From the south a terrible heat "+
"can be felt.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room302","south",
    sr+"/room304","north",
  });
  items = ({
    "walls",
    "They are barely visible in the distance",
    "floor",
    "Loose pebbles and uneven cutting have made this floor hard to walk on",
  });
    clone_list = ({ 
    1, 2, "monster", sm+"/goblin.c", 0 
    });   
  ::reset(arg);
    replace_program("room/room");

}
