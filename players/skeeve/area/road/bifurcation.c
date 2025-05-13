inherit "room/room";

/* Galadriel: room didnt load. rm'ed ; from next line */
#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg)  {
    set_light(1);
    smell="The air smells salty here";
    short_desc = "bifurcation";
    long_desc= "You stand on a bifurcation at the road leading south next to the ocean shore.\n" 
             + "You look at a sign pointing west.\n";
    dest_dir = ({
        ROAD + "northgate", "north",
        OCEAN+ "shore3",    "east",
        ROAD + "road",      "south",
        LAND + "path1",     "west"
       });
    items=({ "shore",        "Behind the shore is a shallow bay",
             "ocean shore",  "Behind the shore is a shallow bay",
             "bay",          "A good place to catch fishes",
             "ocean",        "The ocean is very shallow in the bay",
             "wave",         "It rolls exactly in your direction",
             "waves",        "They roll and roll and roll and ...",

             "north",        "The northern gate",
             "east",         "The ocean shore",
             "south",        "The road to the southern gate",
             "west",         "The path to the cottage of the druid Lakmir",

             "sign",         "There is a map on it",
             "map",          "Maybe you should read it",
             "gate",         "The gate is made of stone and wood",

             "bifurcation",  "The road continous to the north and the south,\n"
                            +"while a path leads to the west",
             "road",         "The road continous you the north and the south",
             "path",         "Its a small and lonesome path"
             });
  }
}

init() {
  ::init();
  add_action("read", "read");
}

read(str) {
  if ((str =="sign") || (str=="map")) {
    write("          northern gate\n"
         +"               I \n"
         +"cottage <- bifurcation\n"
         +"               I\n"
         +"             road\n"
         +"               I\n"
         +"          southern gate\n");
    return 1;
  }
  return 0;
}

move(dir) {   
   if (!dir) dir=query_verb();
   if (this_player()->query_npc()) {
     if (dir=="east") return ::move("north");
     else if (dir=="west") return ::move("south");
   }
     return ::move(dir);
}
