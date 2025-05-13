inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "North-South Hall";
    long_desc =
    "This hall leads north-south. It is illuminated by torches set\n"+
    "high on the walls. The sound of children laughing comes from the\n"+
    "north. A harsh voice scolds the laughter, bringing silence.\n";

    dest_dir = ({
      TFIRE + "nurse","north",
      TFIRE + "ehall4","south",
    });

    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });

    ::reset(arg);
    replace_program("room/room");
}
