#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="In the bushes";
  long_desc=
    "You are hidden in the bushes. To the north you see a wall and to\n"+
    "the west you see the path shimmering between the leaves.\n";
  dest_dir=({PATH+"path3","west"});
  items=({"wall","The wall is made of wood. You discover a little hole in it!",
        "hole","Its a little hole in the wall, maybe you can look through it!",
        "path","You can't see the path very clearly from your hiding place",
        "bushes","The bushes are not very thick",
        "leaves","Green leaves of the bushes"});
}

init() {
  ::init();
  add_action("look","look");
  add_action("look","peek");
  add_action("look","peep");
  add_action("try_get","get");
}

look(arg) {
  if (arg!="through hole" && arg!="through the hole") return;
  write("You peek through the hole and see the inside of a hut!\n"+
        "On a desk you see a lot of forms, papers and other junk.\n"+
        "There is not enough light inside to see it all clearly.\n");
  return 1;
}

try_get(arg) {
  if (arg!="junk" && arg!="form" && arg!="forms"
        && arg!="paper" && arg!="papers") return;
  write("The hole is really too small for that!\n"+
        "Maybe you could return to the main road and enter the huts\n"+
        "through their front door...\n");
  return 1;
}
