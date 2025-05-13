inherit "/room/room";

#include "/players/matt/defs.h"

int vines;

reset(arg) {
  if(vines) vines = 0;
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    Just above the ground here is a fine white mist, hazy and\n" +
    "cold to the touch. The forest itself seems very dense; vines\n" +
    "hang down from the branches of the trees, some of them barely\n" +
    "touching the misty ground. The scene before you seems almost\n" +
    "unearthly, giving you an eerie feeling.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a12", "west",
    NWFORESTA + "rooms/a03", "east",
  });

  items = ({
    "mist", "A thin layer of cold white mist",
    "ground", "You can barely see it for the mist",
    "forest", "It seems more thickly-packed than usual here",
    "vines", "Dark, leafless vines hanging low enough to pull",
    "branches", "They are bowed and hang somewhat low",
    "trees", "The trees are stooped and aged here",
    "scene", "The scene is strange and mysterious",
  });
}

init() {
  ::init();
  add_action("pull", "pull");
}

pull(arg) {
  object network;
  if(arg == "vine" || arg == "vines" ||
     arg == "on vine" || arg == "on vines") {
    write("You pull on the vines.\n");
    say(TP->NAME + " grabs a vine and pulls on it.\n");
    if(!vines) {
      TELLR(ENV(TP), "A huge network of vines falls from the trees!\n");
      vines = 1;
      network = clone_object(NWFORESTA + "monsters/vines");
      MOVE(network, TO);
      return 1;
    }
    TELLR(ENV(TP), "Nothing further happens.\n");
    return 1;
  }
  write("Pull what?\n");
  return 1;
}
