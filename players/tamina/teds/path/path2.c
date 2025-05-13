inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cobblestone Path2";
    long_desc =
    "A cobblestone path leading north-south.\n";

    dest_dir = ({
      TPATH + "path3","north",
      TPATH + "path1","south",
    });

    ::reset();
    replace_program("room/room");
}
