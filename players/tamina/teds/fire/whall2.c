inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "North-South Hall";
    long_desc =
"This hall leads north-south. It is illuminated by torches set\n"+
"high on the walls. The smell of cooking food comes from the\n"+
"north, along with the sound of banging pots and pans.\n";

    dest_dir = ({
      TFIRE + "kitchen", "north",
      TFIRE + "whall4", "south"
    });

    items = ({
"torch","The torches are to high to reach. Anyway, they are almost burt out",
"torches","The torches are to high to reach. Anyway, they are almost burt out"
    });

    ::reset(arg);
    RPR("room/room");
}
