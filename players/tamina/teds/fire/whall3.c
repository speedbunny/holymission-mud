inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Intersection";
    long_desc =
"Here a north-south hall intersects a east hall. It is illuminated\n"+
"by torches set high on the walls. Some unusual sounds come from\n"+
"a door to the south.\n";

    dest_dir = ({
      TFIRE + "whall1", "north",
      TFIRE + "wguard", "south",
      TFIRE + "whall4", "east"
    });

    items = ({
"door", "It is open. Maybe you should go in?",
"south door", "It is open. Maybe you should go in?"
    });

    ::reset(arg);
    RPR("room/room");
}
