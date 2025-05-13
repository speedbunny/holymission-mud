inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave winds and twists northwest and southwest.\n";

    dest_dir = ({
      TFROST + "cave9", "northwest",
      TFROST + "cave7", "southwest"
    });

    ::reset(arg);
    RPR("room/room");
}
