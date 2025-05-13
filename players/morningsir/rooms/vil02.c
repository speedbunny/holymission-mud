inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Forest";
  long_desc=
   "You have come further inside into the forest. There are trees all\n" +
   "around, but they are not very high. Sunlight passes through the holes\n" +
   "in the upper branches so that you can see clearly. You can hear various\n" +
   "sounds coming from above.\n";

  dest_dir=({ PATHR + "vil03.c", "south",
              PATHR + "vil05.c", "east"
             });

  items=({ "forest", "The forest is bright and full of animals.",
           "trees", "The trees are mostly pines.",
           "road", "It's a forest road, quite dirty, but dry after all."
          });

  smell="You feel the pine aroma in the air.";

}

init() {
  ::init(); 
  add_action("climb_tree", "climb");
}

climb_tree(str1) {
  if (str1 != "tree") return;
  write("The tree doesn't seem climbable.\n");
  say(TPN + " tries to climb up a tree but fails.\n");
  return 1;
}

