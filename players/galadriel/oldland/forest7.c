#include "/players/skeeve/area.h";

#define DEST_DIRS ({\
        LAND + "forest8", "north",\
        LAND + "forest4", "east",\
        LAND + "brooklet","west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
