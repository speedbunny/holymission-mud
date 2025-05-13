inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave is very narrow here. Passages leave west and up.\n";

    dest_dir = ({
      TFROST + "cave6", "west",
      TFROST + "cave4", "up"
    });

    ::reset(arg);
    RPR("room/room");
}
