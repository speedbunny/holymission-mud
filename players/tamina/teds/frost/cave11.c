inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Dark Cave";
    long_desc =
"The cave slopes up and winds back to the southwest.\n";

    dest_dir = ({
      TFROST + "cave12", "up",
      TFROST + "cave3", "southwest"
    });

    ::reset(arg);
    RPR("room/room");
}
