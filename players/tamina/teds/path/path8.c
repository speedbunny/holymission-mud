inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cobblestone Path 8";
    long_desc =
    "This is a cobblestone path leading north-south.\n";

    dest_dir = ({
      TPATH + "green","north",
      TPATH + "red","south",
    });

    ::reset();
    replace_program("room/room");
}
