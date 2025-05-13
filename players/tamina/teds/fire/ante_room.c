inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Ante-Room";
    long_desc =
    "Here people who are waiting for an audience with the\n"+
    "the king can sit and talk amongst themselves. It is\n"+
    "comfortably furnished, with couches and tables scattered\n"+
    "around the room. A strange smell comes from the north.\n";

    dest_dir = ({
      TFIRE + "hell_hall","north",
      TFIRE + "courtyard","south"
    });

    ::reset(arg);  
    replace_program("room/room");
}
