inherit "room/room";

/* Galadriel: rm'ed ; from end of next line */
#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc="Ocean shore";
    long_desc= "You are on the road leading south next to the ocean shore.\n" 
             + "Huge waves roll towards the land.\n";
    smell="The air smells salty here";
    dest_dir = ({
      ROAD + "bifurcation", "north",
      OCEAN+ "shore2",      "east",
      ROAD + "southgate",   "south",
      LAND + "meadow2",     "west" 
    });
    items=({ "north",        "There is a bifurcation on the road",
             "east",         "The ocean shore",
             "south",        "The southern gate",
             "west",         "There is a meadow with many flowers",
             
             "gate",         "The gate is made of stone and wood",
             "road",         "This is the road next to the ocean",
             
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
