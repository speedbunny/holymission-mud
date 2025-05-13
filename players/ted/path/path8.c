#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Cobblestone Path 8";
    long_desc =
    "This is a cobblestone path leading north-south.\n";
    dest_dir = ({
      KPATH + "green","north",
      KPATH + "red","south",
    });
    replace_program("room/room");
}
