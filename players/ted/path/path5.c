#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Coblestone path 5";
    long_desc =
    "This is a north-south cobblestone path.\n";
    dest_dir = ({
      KPATH + "path4","south",
      KPATH + "wierd_path","north",
    });
    replace_program("room/room");
}
