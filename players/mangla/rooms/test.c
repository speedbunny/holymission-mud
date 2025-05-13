inherit "room/room";

#include "/players/mangla/defs.h"


reset(arg) {

    if(arg) return;

    set_light(1);

    short_desc = "Mangla's test room";

    long_desc = "Mangla test room. Here monsters are tested so that\n" +
                "they cannot wimpy away.\n";

    property=({"no_teleport","no_sneak"});

}

init() {

    ::init();
}


