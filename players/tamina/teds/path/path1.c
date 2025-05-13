inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Cobblestone Path";
    long_desc =
    "This cobblestone path leads north and south.\n"+
    "Far to the north is king Arthurs castle.\n"+
    "A side street leads off to the east and the west.\n";

    dest_dir = ({
      "players/blade/area/forest1/forest3", "south",
      TPATH + "path2","north",
      TPATH + "road1","west",
      TPATH + "road2","east",
    });

    ::reset();
    replace_program("room/room");
}
