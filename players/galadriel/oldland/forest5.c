#include "/players/skeeve/area.h";

#define DEST_DIRS ({\
        LAND + "clearing", "north",\
        LAND + "forest2", "east",\
        LAND + "forest4", "south",\
        LAND + "forest8", "west"\
    })

inherit LAND+"forest";

reset (arg) { ::reset(arg,DEST_DIRS); }
