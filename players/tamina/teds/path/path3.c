inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cobblestone Path 3";
    long_desc =
"A cobblestone path leading north-south.\n";

    dest_dir = ({
    TPATH + "four_way", "north",
    TPATH + "path2", "south"
    });

  ::reset();
  replace_program("room/room");
}
