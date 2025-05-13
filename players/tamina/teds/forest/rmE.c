inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if (arg) return 0;
    set_light(0);
    short_desc = "Dread Forest";
    long_desc =
"You enter the dreaded Petrified Forest.\n"+
"The trees crowd together here, almost cutting off all\n"+
"the light. As you push through the undergrowth, you can \n"+
"see paths leading off deeper into the forest.\n";

    dest_dir = ({
    TFOREST + "rmJ", "north",
    TFOREST + "rmB", "south",
    TFOREST + "rmF", "east",
    "/players/emerald/perilous/path/four_way","west",
    });

    ::reset();
    replace_program("room/room");
}
