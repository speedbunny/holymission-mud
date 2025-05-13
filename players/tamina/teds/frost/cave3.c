inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave branches here to lead northwest and northeast.\n"+
"The southern part of the cave has more ice and snow than\n"+
"the rest of the cave.\n";

    dest_dir = ({
      TFROST + "cave11", "northeast",
      TFROST + "cave4", "northwest",
      TFROST + "cave2", "south"
    });

    ::reset(arg);
    RPR("room/room");
}
