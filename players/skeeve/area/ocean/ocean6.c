#include "/players/skeeve/area.h"

inherit OCEAN+"ocean";

#define DEST_DIRS ({\
    OCEAN + "ocean7", "north",\
    OCEAN + "ocean5", "south",\
    OCEAN + "ocean2", "west"\
})

reset(arg) { ::reset(arg,DEST_DIRS); }
