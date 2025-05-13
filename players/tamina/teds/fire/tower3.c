inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "End of Hall";
    long_desc =
"You are at the end of a short hallway. Doors lead\n"+
"east and west.\n";

    dest_dir = ({
      TFIRE + "tower2", "north",
      TFIRE + "tower_capt", "west",
      TFIRE + "tower_sarg", "east"
    });

    ::reset(arg);
    RPR("room/room");
}
