inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cobblestone Path 9";
    long_desc =
    "This is a cobblestone path leading north-south.\n";

    dest_dir = ({
      TPATH + "black","north",
      TPATH + "green","south",
    });

    ::reset();

    replace_program("room/room");
}
