inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Coblestone path 5";
    long_desc =
    "This is a north-south cobblestone path.\n";

    dest_dir = ({
      TPATH + "path4","south",
      TPATH + "wierd_path","north",
    });

    clone_list = ({
      1, 1, "pageboy", "/players/tamina/castle/monsters/page", 0 });

    ::reset(arg);

    replace_program("room/room");
}
