inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Desert";
    long_desc =
    "A huge desert full of shifting sands and buring dunes\n"+
    "stretches from horizon to horizon.\n";

    dest_dir = ({
      THOT + "fire_troll","north",
      THOT + "salamander","south",
      THOT + "lizard","west",
      THOT + "fire_elem","east"
    });

    ::reset(arg);
    replace_program("room/room");
}
