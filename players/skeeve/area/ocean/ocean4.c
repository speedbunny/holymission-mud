#include "/players/skeeve/area.h"

inherit OCEAN+"ocean";

#define DEST_DIRS ({\
    OCEAN + "ocean8", "east",\
    OCEAN + "ocean3", "south",\
    OCEAN + "shore4", "west"\
})

reset(arg) { ::reset(arg,DEST_DIRS); }

/* fishes stay at sea! */
move(dir) {
   if (!dir) dir = query_verb();
   return ((this_player()->query_race() == "fish") && (dir=="west")) ?
     ::move("east") : ::move(dir);
}
