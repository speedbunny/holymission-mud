inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave slopes sharply down to the west and becomes narrower.\n"+
"To the southeast the cave widens out a bit.\n";

    dest_dir = ({
      TFROST + "cave5", "down",
      TFROST + "cave3", "southeast"
    });

    ::reset(arg);
    RPR("room/room");
}
