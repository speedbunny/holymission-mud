inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Marble Hallway";
    long_desc =
"This well lit hall is made of marble, beautifuly carved and\n"+
"shined. It is very clean and you almost can't tell you're\n"+
"underground at all.\n";

    dest_dir = ({
      TFROST + "entrance", "northeast",
      TFROST + "lady", "northwest"
    });

    ::reset(arg);
    RPR("room/room");
}
