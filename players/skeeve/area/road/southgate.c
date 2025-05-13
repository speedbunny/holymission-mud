inherit "room/room";

/* Galadriel: rm'ed ';'. no good since new parser 110893 */
#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Southern Gate";
    long_desc = "This is the southern gate to the land of the druid Lakmir.\n";
    dest_dir = ({
      ROAD + "road",   "north",
      OCEAN+"shore1",    "east",
      "room/shore/s17",  "south",
      LAND+"meadow1",  "west" 
    });
    items=({ "north",        "The road to the northern gate",
             "east",         "The ocean shore",
             "south",        "The road continous in the south",
             "west",         "There is a meadow with many flowers",
             
             "gate",         "The gate is made of stone and wood",
             
             "shore",        "Behind the shore is a shallow bay",
             "ocean shore",  "Behind the shore is a shallow bay",
             "bay",          "A good place to catch fishes",
             "ocean",        "The ocean is very shallow in the bay",
             "wave",         "It rolls exactly in your direction",
             "waves",        "They roll and roll and roll and ...",
             
             "meadow",       "There are flowers on the meadow",
             "flowers",      "There are flowers in all colors. \n"
                            +"You are not near enough to see more"
             });
  }
}

move(dir) {
   if (!dir) dir=query_verb();
   if (this_player()->query_npc()) {
     if (dir=="east") return ::move("north");
     else if (dir=="west") return ::move("south");
   }
     return ::move(dir);
}
