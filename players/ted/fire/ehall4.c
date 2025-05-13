#include "/players/ted/defs.h"


inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Intersection";
    long_desc =
    "Here a north-south hall intersects a east hall. It is illuminated\n"+
    "by torches set high on the walls. An open door leads south.\n";
    dest_dir = ({
      FIRE + "ehall2","north",
      FIRE + "ehall3","west",
      FIRE + "eguard","south",
    });
    items = ({
      "torchs","The torches are almost burnt out here",
      "torch","The torches are almost burnt out here"
    });
    replace_program("room/room");
}
