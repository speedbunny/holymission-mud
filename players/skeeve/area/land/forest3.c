#include "/players/skeeve/area.h"

#define DEST_DIRS ({\
        LAND + "forest11", "east",\
        LAND + "path2",    "south",\
        LAND + "forest6",  "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
