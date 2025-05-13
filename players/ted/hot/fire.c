#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Desert";
    long_desc =
    "A huge desert full of shifting sands and buring dunes\n"+
    "stretches from horizon to horizon.\n";
    dest_dir = ({
      HOT + "fire_troll","north",
      HOT + "salamander","south",
      HOT + "lizard","west",
      HOT + "fire_elem","east"
    });
    replace_program("room/room");
}
