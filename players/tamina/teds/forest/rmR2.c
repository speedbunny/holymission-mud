inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(0);
    short_desc = "In a dark Cave";
    long_desc =
"You are in a dark cave.\n"+
"The passage continues to the east, and gets lighter \n"+
"back to the west.\n";

    dest_dir = ({
    TFOREST + "rmR3", "east",
    TFOREST + "rmR", "west",
    });

    ::reset();
    replace_program("room/room");
}
