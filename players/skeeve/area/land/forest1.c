#include "/players/skeeve/area.h"

#define DEST_DIRS ({\
        LAND + "forest2", "north",\
        LAND + "pasture", "east",\
        LAND + "forest4", "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
