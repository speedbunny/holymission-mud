#include "/players/skeeve/area.h"

inherit OCEAN+"ocean";

#define DEST_DIRS ({\
    OCEAN + "ocean8", "north",\
    OCEAN + "ocean6", "south",\
    OCEAN + "ocean3", "west"\
})

reset(arg) { ::reset(arg,DEST_DIRS); }

