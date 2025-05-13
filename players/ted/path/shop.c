#include "/players/ted/defs.h"

inherit "room/shop";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("The Golden Fleece Store");
    set_long("You are in the Golden Fleece Shop and Emporium. Only\n"+
      "the finest goods are sold here, so shop away!\n\n"+
      "Commands: 'list', 'list armors', 'list weapons'\n"+
      "          'Sell <item>', 'sell all'\n");
    set_store_room("room/store");
    set_store_exit("south");
    set_exits(({ KPATH+"road2","north" }));
    set_light(1);
}
