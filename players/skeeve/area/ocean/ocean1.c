#include "/players/skeeve/area.h"

inherit OCEAN+"ocean";

#define DEST_DIRS ({\
    OCEAN + "ocean2", "north",\
    OCEAN + "ocean5", "east",\
    OCEAN + "shore1", "west"\
})


reset(arg) { ::reset(arg, DEST_DIRS); }

/* fishes stay at sea */
move(dir) {
   if (!dir) dir=query_verb();
   return ((this_player()->query_race() == "fish") && (dir=="west")) ?
     ::move("east") : ::move(dir);
}

