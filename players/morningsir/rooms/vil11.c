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
   "sounds coming from above. There is also a path to north which seems to\n" +
   "lead into a clearing.\n";

  dest_dir=({ PATHR + "vil10.c", "north",
              PATHR + "vil12.c", "south",
              PATHR + "vil08.c", "west",
              PATHR + "vil20.c", "east"
             });

  items=({ "forest", "The forest is bright and full of animals.",
           "trees", "The trees are mostly pines.",
           "road", "It's a forest road, quite dirty, but dry after all.",
           "clearing", "It looks like there are some animals playing on the clearing."
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

