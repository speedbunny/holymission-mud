inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Hot Path";
    long_desc =
"This path becomes hotter the farther east you go.\n";

    dest_dir = ({
   TPATH + "wierd_path", "west",
   THOT + "fire_path", "east"
    });

    ::reset(arg);
    replace_program("room/room");
}
