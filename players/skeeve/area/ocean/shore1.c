#include "/players/skeeve/area.h"

inherit OCEAN+"shore.c";

#define DEST_DIRS ({\
        OCEAN + "shore2",  "north",\
        OCEAN + "ocean1",  "east",\
        ROAD + "southgate","west"\
    })

reset(arg) { ::reset(arg, DEST_DIRS); }
