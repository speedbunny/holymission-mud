#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Volcano Rim";
    long_desc =
    "You are standing on the rim of a huge crater. You can see\n"+
    "smoking cracks and fissures on the bottom of the crater.\n"+
    "Something can almost be seen through the smoke and haze\n"+
    "at the eastern part of the crater.\n";
    dest_dir = ({
      HOT + "volcano","down",
      HOT + "crater","east",
    });
    replace_program("room/room");
}
