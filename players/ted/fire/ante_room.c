#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Ante-Room";
    long_desc =
    "Here people who are waiting for an audience with the\n"+
    "the king can sit and talk amongst themselves. It is\n"+
    "comfortably furnished, with couches and tables scattered\n"+
    "around the room. A strange smell comes from the north.\n";
    dest_dir = ({
      FIRE + "hell_hall","north",
      FIRE + "courtyard","south"
    });
    replace_program("room/room");
}
