inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) {
  if (arg) return 0;

    set_light(1);
    short_desc = "Petrified Forest";
    long_desc =
"You are in the dreaded Petrified Forest.\n"+
"All around you are sounds of wildlife and nature.\n";

    dest_dir = ({
    TFOREST + "rmN", "north",
    TFOREST + "rmC", "south",
    TFOREST + "rmI", "east",
    TFOREST + "rmG", "west",
    });

    ::reset(arg);
    replace_program("room/room");
}
