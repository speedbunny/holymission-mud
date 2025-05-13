inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if(arg) return 0;
  set_light(1);
  short_desc = "South of Hot Path";
  long_desc =
"The heat is more intense here. A large pool of lava\n"+
"is exposed to the open air south of here.\n";

    dest_dir = ({
   THOT + "fire_path", "north",
   THOT + "fire_troll", "south"
    });

    ::reset(arg);
    replace_program("room/room");
}
