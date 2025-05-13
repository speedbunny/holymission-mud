inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(1);
    short_desc = "Petrified Forest";
    long_desc =
"You are in the dreaded Petrified Forest.\n"+
"You feel the oppression of darkness smother you.\n";

    dest_dir = ({
    TFOREST + "rmT", "north",
    TFOREST + "rmH", "south",
    TFOREST + "rmM", "west",
    });

    ::reset();
    replace_program("room/room");
}
