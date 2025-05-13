#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Intersecting Hall";
    long_desc =
    "This is a small intersection between a north-south hall and\n"+
    "a west hall. It is illuminated by torches set high on the walls.\n";
    dest_dir = ({
      FIRE + "ehall1","north",
      FIRE + "etower_bot","south",
      FIRE + "courtyard","west",
      FIRE +"ehall4","east",
    });
    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });
    replace_program("room/room");
}
