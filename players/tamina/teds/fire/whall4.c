inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Intersecting Hall";
    long_desc =
"This is a small intersection between a north-south hall and\n"+
"a west hall. It is illuminated by torches set high on the walls.\n";

    dest_dir = ({
      TFIRE + "whall2", "north",
      TFIRE + "wtower_bot", "south",
      TFIRE + "whall3", "west",
      TFIRE + "courtyard", "east"
    });

    items = ({
"torch", "The torches are to high to reach. Anyway, they are almost burt out",
"torches", "The torches are to high to reach. Anyway, they are almost burt out"
    });

    ::reset(arg);
    RPR("room/room");
}
