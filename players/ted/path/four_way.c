#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Four Way Intersection";
    long_desc =
    "Here the north-south cobblestone path intercepts a\n"+
    "east-west dirt path. This path leads through the\n"+
    "Dread Forest. The Dread Forest is renowned for its\n"+
    "many evil monsters. It is the proving ground for\n"+
    "new Knights of the Round Table.\n";
    dest_dir = ({
      KPATH + "path3","south",
      KPATH + "path4","north",
      "players/ted/forest/forest23", "east",
      "players/ted/forest/forest22","west"
    });
    replace_program("room/room");
}
