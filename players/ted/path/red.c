#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Red Pavilion";
    long_desc =
    "A blood red pavilion sits in a clearing to one side\n"+
    "of the path here. A large oak is adorned with the trophies\n"+
    "collected by the occupant of the pavilion.\n";
    dest_dir = ({
      KPATH + "path8","north",
      KPATH + "path7","south",
    });
    items = ({
      "pavilion","A large, blood red tent, usualy used by Knights and nobles",
      "oak","The bloodied armor and remains of human corpses hang from the branches"
    });
    clone_list = ({
      1,1,"red horn","players/ted/items/red_horn",0,
    });
    ::reset();
    replace_program("room/room");
}
