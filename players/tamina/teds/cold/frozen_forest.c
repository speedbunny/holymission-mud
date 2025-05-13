inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Frozen Forest";
    long_desc =
"The trees here are covered in frost and snow. A winding path\n"+
"leading north has been trampled by LARGE feet.\n";

    dest_dir = ({
  TCOLD + "frost_giant", "north",
  TCOLD + "ice_path", "south"
    });

    ::reset(arg);
    replace_program("room/room");
}
