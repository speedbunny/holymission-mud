#include "/players/skeeve/area.h"

#define DEST_DIRS ({\
        LAND + "forest0", "east",\
        LAND + "fork",    "south",\
        LAND + "forest3", "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
