#include "/players/skeeve/area.h"

#define DEST_DIRS ({\
        LAND + "path2", "north",\
        LAND + "path3", "east",\
        LAND + "forest1", "south",\
        LAND + "forest5", "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
