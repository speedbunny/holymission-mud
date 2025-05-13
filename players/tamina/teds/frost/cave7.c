inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave winds and twists northeast and south.\n";

    dest_dir = ({
       TFROST + "cave8", "northeast",
       TFROST + "cave6", "south"
    });

     ::reset(arg);
     RPR("room/room");
}
