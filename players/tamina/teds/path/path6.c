inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cobblestone Path 6";
    long_desc =
    "This is a cobblestone path that runs north-south.\n";

    dest_dir = ({
      TPATH + "path7","north",
      TPATH + "wierd_path","south",
    });

    ::reset();
    replace_program("room/room");
}
