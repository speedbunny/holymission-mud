#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Cobblestone path 4";
    long_desc =
    "This path leads north-south.\n";
    dest_dir = ({
      KPATH + "four_way","south",
      KPATH + "path5","north",
    });
    replace_program("room/room");
}
