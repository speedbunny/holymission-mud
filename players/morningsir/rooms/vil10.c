inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Forest clearing";
  long_desc=
   "You have arrived at the forest clearing. It is all green and there are some\n" +
   "animals drinking and playing. Trees are everywhere around and the only exit\n" +
   "seems to be in the southern direction. There is a small stream from which\n" +
   "animals are watering themselves.\n";

  dest_dir=({ PATHR + "vil08.c", "southwest",
              PATHR + "vil11.c", "south",
              PATHR + "vil13.c", "southeast"
             });

  items=({ "forest", "The forest is bright and full of animals.",
           "trees", "The trees are mostly pines.",
           "animals", "Sure, go ahead! LOOK AT them if you can!",
           "stream", "It is a natural stream flowing out of a rock and the water is cool."
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

