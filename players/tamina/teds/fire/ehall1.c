inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "North-South Hall";
    long_desc =
    "This is a north-south hall. It is illuminated by torches.\n"+
    "There are no windows or other openings. The sound of your\n"+
    "footsteps echo down the hall.\n";

    dest_dir = ({
      TFIRE + "estairs","north",
      TFIRE + "ehall3","south"
    });

    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });

    ::reset(arg);
    replace_program("room/room");
}
