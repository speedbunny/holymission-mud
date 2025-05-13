#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Very Hot Path 2";
    long_desc =
    "The smell of buring sulphur and lava is almost choking.\n"+
    "A huge volcano lies to the east.\n";
    dest_dir = ({
      HOT + "fire_path","west",
      HOT + "volcano","east"
    });
    replace_program("room/room");
}
