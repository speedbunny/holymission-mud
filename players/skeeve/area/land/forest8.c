#include "/players/skeeve/area.h"

#define DEST_DIRS ({\
        LAND + "forest9", "north",\
        LAND + "forest5", "east",\
        LAND + "forest7", "south",\
        LAND + "hillside1", "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
