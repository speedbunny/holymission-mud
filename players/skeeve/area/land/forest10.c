#include "/players/skeeve/area.h"

#define DEST_DIRS ({\
        LAND + "forest6", "east",\
        LAND + "forest9", "south",\
        LAND + "hillside2", "west",\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
