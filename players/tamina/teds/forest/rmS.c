inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(0);
    short_desc = "Dread Forest";
    long_desc =
"You are in the depths of the dreaded Petrified Forest.\n"+
"To the east, you can see a path leading out of the forest.\n";

    dest_dir = ({
    TFOREST + "rmM", "south",
    TFOREST + "rmT", "east",
    });

    ::reset();
    replace_program("room/room");
}
