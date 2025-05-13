inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Intersection";
    long_desc =
    "Here a north-south hall intersects a east hall. It is illuminated\n"+
    "by torches set high on the walls. An open door leads south.\n";

    dest_dir = ({
      TFIRE + "ehall2","north",
      TFIRE + "ehall3","west",
      TFIRE + "eguard","south",
    });

    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });

    ::reset(arg);
    replace_program("room/room");
}
