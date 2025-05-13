#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cobblestone path 4";
    long_desc =
    "This path leads north-south.\n";

    dest_dir = ({
      TPATH + "four_way","south",
      TPATH + "path5","north",
    });

    ::reset();
    replace_program("room/room");
}
