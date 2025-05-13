inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;

    set_light(0);
    short_desc = "Petrified Forest";
    long_desc =
"You enter the dreaded Petrified Forest surrounding Camelot.\n"+
"The forest lightens to the east, as you leave it.\n"+
"A small hill rises to the north and a strange squawking \n"+
"sound comes from the south.\n";

    dest_dir = ({
    TFOREST + "rmI", "north",
    TFOREST + "rmA", "south",
    "/players/emerald/perilous/path/four_way","east",
    TFOREST + "rmC", "west",
    });

    ::reset(arg);

    replace_program("room/room");
}
