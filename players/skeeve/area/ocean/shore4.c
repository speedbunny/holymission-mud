#include "/players/skeeve/area.h"

inherit OCEAN+"shore.c";

#define DEST_DIRS ({\
        ROAD + "northgate", "west",\
        OCEAN + "shore3",   "south",\
        OCEAN + "ocean4",   "east"\
    })

reset (arc) { ::reset(arc,DEST_DIRS); }
