#include "/players/skeeve/area.h"

#define DEST_DIRS ({\
        LAND + "forest10", "north",\
        LAND + "clearing", "east",\
        LAND + "forest8",  "south",\
        LAND + "valley",   "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
