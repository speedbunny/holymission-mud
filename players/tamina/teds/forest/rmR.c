inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(0);
    short_desc = "In a dark Cave";
    long_desc =
"You are in a dark cave.\n"+
"To the north and south, you can see light sources.\n"+
"But to the east, the caves go into deeper darkness.\n";

    dest_dir = ({
    TFOREST + "rmX", "north",
    TFOREST + "rmL", "south",
    TFOREST + "rmR2", "east",
    });

    ::reset();
    replace_program("room/room");
}
