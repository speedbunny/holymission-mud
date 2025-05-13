#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Cobblestone Path";
    long_desc =
    "This cobblestone path leads north and south.\n"+
    "Far to the north is king Arthurs castle.\n"+
    "A side street leads off to the east and the west.\n";
    dest_dir = ({
      "room/deep_forest1","south",
      KPATH + "path2","north",
      KPATH + "road1","west",
      KPATH + "road2","east",
    });
    replace_program("room/room");
}
