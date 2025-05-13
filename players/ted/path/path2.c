#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Cobblestone Path2";
    long_desc =
    "A cobblestone path leading north-south.\n";
    dest_dir = ({
      KPATH + "path3","north",
      KPATH + "path1","south",
    });
    replace_program("room/room");
}
