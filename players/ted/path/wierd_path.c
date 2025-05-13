#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Hot/Cold Path";
    long_desc =
    "As you walk along this path, you can feel\n"+
    "cold air coming from the west and hot air\n"+
    "flowing from the east.\n";
    dest_dir = ({
      COLD + "cold_path","west",
      HOT + "hot_path","east",
      KPATH + "path5","south",
      KPATH + "path6","north",
    });
    replace_program("room/room");
}
