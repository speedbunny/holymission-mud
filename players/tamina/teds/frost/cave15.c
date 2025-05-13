inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave is almost a hallway now. The floor and walls are lined\n"+
"with cut slabs of white marble.\n";

    dest_dir = ({
      TFROST + "cave16", "northwest",
      TFROST + "cave14", "south"
    });

    ::reset(arg);
    RPR("room/room");
}
