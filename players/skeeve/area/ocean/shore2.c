#include "/players/skeeve/area.h"

inherit OCEAN+"shore.c";

#define DEST_DIRS ({\
        OCEAN + "shore3", "north",\
        OCEAN + "ocean2", "east",\
        OCEAN + "shore1", "south",\
        ROAD + "road",    "west",\
    })

reset(arg) { ::reset(arg, DEST_DIRS); }
