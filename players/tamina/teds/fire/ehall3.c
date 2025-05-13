inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Intersecting Hall";
    long_desc =
    "This is a small intersection between a north-south hall and\n"+
    "a west hall. It is illuminated by torches set high on the walls.\n";

    dest_dir = ({
      TFIRE + "ehall1","north",
      TFIRE + "etower_bot","south",
      TFIRE + "courtyard","west",
      TFIRE +"ehall4","east",
    });

    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });

    ::reset(arg);
    replace_program("room/room");
}
