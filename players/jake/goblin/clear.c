

inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
    if (arg) return;

    set_light(3);
    short_desc = "Entrance to a cemetary";
    long_desc = 
        "You stand in a small clearing.  A large iron fence stands to the\n" +
        "east, and a dense forest is to the north.  A small path through some\n" +
        "bushes leads south.  You can see several large stones through the\n" +
        "open gate to the east.\n";
items = ({
"gate","An open iron gate",
"fence","A large iron fence",
"stones","It is hard to see what exactly they are from here",
});
    dest_dir = 
        ({
"players/jake/goblin/croad2","west",
"players/jake/goblin/cleara","south",
"players/jake/goblin/cl1","east",
        });
}

