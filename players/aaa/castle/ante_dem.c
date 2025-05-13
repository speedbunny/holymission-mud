
#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    set_light(2);
    short_desc="Under construction";
    long_desc="Under construction. \n"+
      "You see the Element of Earth making the foundation works.\n";
    dest_dir=({ PA + "castle/qwrkroom.c","up",
                PA + "castle/prg_room.c","down"});
}
