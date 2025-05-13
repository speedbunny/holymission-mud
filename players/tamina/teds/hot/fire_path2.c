inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Very Hot Path 2";
    long_desc =
    "The smell of buring sulphur and lava is almost choking.\n"+
    "A huge volcano lies to the east.\n";

    dest_dir = ({
      THOT + "fire_path","west",
      THOT + "volcano","east"
    });

    ::reset(arg);
    replace_program("room/room");
}
