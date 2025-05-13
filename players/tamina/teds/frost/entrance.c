inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Marble Hallway";
    long_desc =
"This well lit hallway is made of marble, beautifuly carved\n"+
"and highly polished. It is very clean and bright, you almost\n"+
"can't tell your underground at all.\n";

    dest_dir = ({
      TFROST + "cave17", "southeast",
      TFROST + "cave10", "southwest",
      TFROST + "study", "north"
    });

    ::reset(arg);
    RPR("room/room");
}
