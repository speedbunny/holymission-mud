inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(0);
    short_desc = "Petrified Forest";
    long_desc =
"You are deep in the dreaded Petrified Forest.\n"+
"To the east, you can see an entrance into a cave in the\n"+
"wall of the mountain.  Other paths lead into the forest.\n";

    dest_dir = ({
    TFOREST + "rm2", "north",
    TFOREST + "rmQ", "south",
    TFOREST + "rmX", "east",
    TFOREST + "rmV", "west",
    });

    ::reset();
    replace_program("room/room");
}
