#include "/players/skeeve/area.h"

inherit OCEAN+"shore.c";

#define DEST_DIRS ({\
        OCEAN + "shore4",     "north",\
        OCEAN + "ocean3",     "east",\
        OCEAN + "shore2",     "south",\
        ROAD + "bifurcation", "west"\
    })

reset(arg) { ::reset(arg, DEST_DIRS); }
