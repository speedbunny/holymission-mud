inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "South of Ice Covered Path";
    long_desc =
"To the south can bee seen a frozen stream and a small\n"+
"wooden bridge.\n";

    dest_dir = ({
  TCOLD + "ice_path", "north",
  TCOLD + "ice_troll", "south"
    });

    ::reset(arg);
    replace_program("room/room");
}
