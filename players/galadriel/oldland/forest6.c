#include "/players/skeeve/area.h";

#define DEST_DIRS ({\
        LAND + "forest3",  "east",\
        LAND + "clearing", "south",\
        LAND + "forest10", "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
