#include "/players/skeeve/area.h"

inherit OCEAN+"ocean";

#define DEST_DIRS ({\
    OCEAN + "ocean7", "south",\
    OCEAN + "ocean4", "west",\
})

reset(arg) { ::reset(arg,DEST_DIRS); }
