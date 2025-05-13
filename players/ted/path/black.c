#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "Black pavilion";
    long_desc =
    "A midnight black pavilion sits in a clearing to one side\n"+
    "of the path. A massive oak holds the trophies of some evil\n"+
    "and powerful champion. Its branches are adorned with Human Heads!\n";
    dest_dir = ({
/*
      PATH + "castle/draw_bridge","north",
*/
      "/players/tamina/castle/rooms/draw_bridge", "north",
      KPATH + "path9","south",
    });
    items = ({
      "pavilion","A large round tent. It's blackness is quite impressive",
      "oak","The rotting heads of many knights hang from the branches",
      "heads","These heads are rotting and worm eaten"
    });
    clone_list = ({
      1,1,"black horn","players/ted/items/black_horn",0,
      2,1,"bush","players/kasgaroth/poison/bush",0,
    });
    ::reset();
    replace_program("/room/room");
}
