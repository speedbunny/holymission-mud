inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Orc kitchen";
  long_desc =
"This appears to be the orc kitchen.  It is empty as of the moment.  "+
"a kettle sits on the stove and vibrates emitting a humming sound.  "+
"Several chicken corpses hang from the ceiling by hooks.  A side "+
"of beef lies on the counter.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room602","northwest",
    sr+"/room604","southeast",
  });
  items =({
   "stove",
   "A huge wood fuel stove",
   "kettle",
   "A kettle of boiling something, you don't want to get close enough to find out",
    "corpses",
    "A chicken corpse hung up to drip dry of blood",
    "beef",
    "One side of a massive cow",
  });
    clone_list = ({ 
       1, 1, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
