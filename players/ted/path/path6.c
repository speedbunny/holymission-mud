#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Cobblestone Path 6";
    long_desc =
    "This is a cobblestone path that runs north-south.\n";
    dest_dir = ({
      KPATH + "path7","north",
      KPATH + "wierd_path","south",
    });
    replace_program("room/room");
}
