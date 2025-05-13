#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "North-South Hall";
    long_desc =
    "This is a north-south hall. It is illuminated by torches.\n"+
    "There are no windows or other openings. The sound of your\n"+
    "footsteps echo down the hall.\n";
    dest_dir = ({
      FIRE + "estairs","north",
      FIRE + "ehall3","south"
    });
    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });
    replace_program("room/room");
}
