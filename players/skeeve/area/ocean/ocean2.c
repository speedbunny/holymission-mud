#include "/players/skeeve/area.h"

inherit OCEAN+"ocean";

#define DEST_DIRS ({\
    OCEAN + "ocean3",   "north",\
    OCEAN + "ocean6",   "east",\
    OCEAN + "ocean1",   "south",\
    OCEAN + "shore2", "west"\
})

reset(arg) { ::reset(arg,DEST_DIRS); }

/* fishes stay at sea */
move(dir) {
   if (!dir) dir = query_verb();
   return ((this_player()->query_race() == "fish") && (dir=="west")) ?
     ::move("east") : ::move(dir);
}
