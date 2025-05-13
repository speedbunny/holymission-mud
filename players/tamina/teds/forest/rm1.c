inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(0);
    short_desc = "Petrified Forest";
    long_desc =
"You enter the dreaded Petrified Forest.\n"+
"Darkness surrounds you, and paths lead in all directions,\n"+
"deeper into the forest.\n";

    dest_dir = ({
    TFOREST + "rm5", "north",
    TFOREST + "rmV", "south",
    TFOREST + "rm2", "east",
    "/players/emerald/perilous/path/green","west",
    });

    ::reset();
    replace_program("room/room");
}
