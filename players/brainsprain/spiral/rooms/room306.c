inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark hall";
  long_desc =
"The size of the hallway widens considerably here.  Lining the walls "+
"are wooden beams, about one foot on a side.  You get the feeling that.  "+
"they may be the only thing holding the ceiling up.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room305","southeast",
    sr+"/room307","west",
  });
  items = ({
    "beams",
    "Massive wooden beams, lined up one on top of each other",
  });
    clone_list = ({ 
       1, 1, "monster", sm+"/goblin.c", 0,
       2, 1, "mystic",sm+"/goblin_mystic.c",0,
    });   
  ::reset(arg);
    replace_program("room/room");
}
