#include "/players/skeeve/area.h"

inherit OCEAN+"ocean";

#define DEST_DIRS ({\
    OCEAN + "ocean6", "north",\
    OCEAN + "ocean1", "west"\
})

reset(arg) { ::reset(arg,DEST_DIRS); }
