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
      TFIRE + "wstairs", "north",
      TFIRE + "whall3", "south"
    });

    items = ({
"torch","The torches are almost burnt out here",
"torches","The torches are almost burnt out here"
    });

    ::reset(arg);
    RPR("room/room");
}
