#include "/players/skeeve/area.h";

#define DEST_DIRS ({\
        LAND + "forest5", "north",\
        LAND + "forest1", "east",\
        LAND + "forest7", "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
