inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark hall";
  long_desc =
"  Shadows obscure large sections of this room, despite your light.  Along\n"+
"  the walls are wooden beams, about one foot on a side.  You get the feeling\n"
+
"  that they may be the only thing holding the ceiling up.\n"+
"\n";
    set_light(0);
    dest_dir = ({
    sr+"/room309","southwest",
    sr+"/room307","east",
  });
  items = ({
    "shadows",
    "These shadows leave the exact shape of the room to the imagination",
    "beams",
    "massive wooden beams, lined up one on top of each other",
  });
    clone_list = ({ 
       1, 3, "monster", sm+"/goblin_mystic.c", 0,
    });   
  ::reset(arg);
    replace_program("room/room");
}
