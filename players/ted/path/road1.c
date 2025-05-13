#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Brick Road";
    long_desc =
    "This short brick road ends here. There is a shop to the south.\n";
    dest_dir = ({
      KPATH + "path1","east",
      KPATH + "magic","south",
    });
    replace_program("room/room");
}
