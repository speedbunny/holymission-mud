inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Forest road";
  long_desc=
   "You have arrived at the entrance to the forest. You can hear various\n" +
   "sounds coming from above. The road seems to continue westward deeper\n" +
   "in the forest while to the east it leads to the village. You can see\n" +
   "houses of the village and citizens walking on the streets.\n";

  dest_dir=({ PATHR + "vil18.c", "west",
              PATHR + "vil20.c", "north",
              PATHR + "vil22.c", "east"
             });

  items=({ "forest", "The forest seems to be bright and full of animals.",
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

