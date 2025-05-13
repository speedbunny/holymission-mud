inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The floor of the cave is paved and the walls are lined with\n"+
"cut marble. You think you hear the sound of running water.\n";

    dest_dir = ({
      TFROST + "cave15", "north",
      TFROST + "cave13", "south"
    });

    ::reset(arg);
    RPR("room/room");
}
