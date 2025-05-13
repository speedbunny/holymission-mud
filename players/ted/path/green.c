#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Green pavilion";
    long_desc =
    "An olive green pavilion sits in a clearing to one side of\n"+
    "the path. A large oak nearby holds the remains of the challengers\n"+
    "to the owner of the pavilion.\n";
    dest_dir = ({
      KPATH + "path9","north",
      KPATH + "path8","south",
    });
    items = ({
      "pavilion","A large round tent. It's bright green color is sinister",
      "oak","This massive oak has the rotting corpses of many knights\n"+
      "skewered on it's mighty branches"
    });
    clone_list = ({
      1,1,"green horn","players/ted/items/green_horn",0,
    });
    ::reset();
    replace_program("room/room");
}
