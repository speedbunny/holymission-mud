inherit "room/room";

/*Herp says: don't use a ; after an #include */

#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Northern Gate";
    long_desc = "This is the northern gate to the land of the druid Lakmir.\n";
    dest_dir = ({
      "room/shore/s16",  "north",
      OCEAN+"shore4",    "east",
      ROAD+"bifurcation","south",
      LAND+"forest0",  "west" 
    });
    items=({ "north",        "The road along the shore to the city",
             "east",         "The ocean shore",
             "south",        "The bifurcation",
             "west",         "The dark forest",
             
             "gate",         "The gate is made of stone and wood",
             
             "shore",        "Behind the shore is a shallow bay",
             "ocean shore",  "Behind the shore is a shallow bay",
             "bay",          "A good place to catch fishes",
             "ocean",        "The ocean is very shallow in the bay",
             "wave",         "It rolls exactly in your direction",
             "waves",        "They roll and roll and roll and ..."
           });
  }
  CASTLE->add_monster("danseuse","/room/vill_green"); /* "/room/vill_green" */
  CASTLE->add_monster("paperboy","/room/vill_green");
}

move(dir) {   
   if (!dir) dir=query_verb();
   if (this_player()->query_npc()) {
     if (dir=="east") return ::move("north");
     else if (dir=="west") return ::move("south");
   }
     return ::move(dir);
}
