#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "North-South Hall";
    long_desc =
    "This hall leads north-south. It is illuminated by torches set\n"+
    "high on the walls. The sound of children laughing comes from the\n"+
    "north. A harsh voice scolds the laughter, bringing silence.\n";
    dest_dir = ({
      FIRE + "nurse","north",
      FIRE + "ehall4","south",
    });
    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });
    replace_program("room/room");
}
