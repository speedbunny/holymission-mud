inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Forest road";
  long_desc=
   "You have arrived to the entrance of the forest. Animal sounds can be heard\n" +
   "from the east, where the road continues. You can hear a river flowing in a\n" +
   "distance. There is a sign hammered in a tree.\n";

  dest_dir=({ PATHR + "vil01.c", "west",
              PATHR + "vil02.c", "north",
              PATHR + "vil04.c", "south",
              PATHR + "vil06.c", "east"
             });

  items=({ "forest", "The forest is bright and full of animals.",
           "road", "It's a forest road, quite dirty, but dry after all.",
           "trees", "The trees are mostly pines.",
           "sign", "It's a wooden sign, you could probably read it."
          });

  smell="You feel the pine aroma in the air.";

}

init() {
  ::init(); 
  add_action("climb_tree", "climb");
  add_action("read_sign", "read");
}

read_sign(str1) {
  if (str1 != "sign") return;
  write("  Welcome adventurers!\n\n" +
        "  Anduin  <--forest-->  village\n");
  say(TPN + " reads the sign on the tree.\n");
  return 1;
}

climb_tree(str1) {
  if (str1 != "tree") return;
  write("The tree doesn't seem climbable.\n");
  say(TPN + " tries to climb up a tree but fails.\n");
  return 1;
}
