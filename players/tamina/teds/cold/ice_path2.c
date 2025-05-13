inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Frozen Path 2";
    long_desc =
"This ice covered path is very slippery.\n"+
"A large mountain of ice towers to the west.\n";

    dest_dir = ({
  TCOLD + "ice_path", "east",
  TCOLD + "ice_cave", "west"
    });

    ::reset(arg);
    replace_program("room/room");
}
