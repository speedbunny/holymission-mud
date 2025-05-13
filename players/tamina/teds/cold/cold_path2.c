inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cold Path 2";
    long_desc =
"This path gets colder the farther west you go.\n";

    dest_dir = ({
  TCOLD + "cold_path", "east",
  TCOLD + "ice_path", "west"
    });

    ::reset(arg);
    replace_program("room/room");
}
