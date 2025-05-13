inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    The path is very overgrown here, but you can still see\n" +
    "that it leads southeast and west. A deep blue sky peeks out\n" +
    "from beyond the branches overhead, and the air is warm and\n" +
    "dry. From the trees surrounding this area you can hear the\n" +
    "calls of strange and exotic birds.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b13", "west",
    NWFORESTB + "rooms/b18", "southeast",
  });

  items = ({
    "sky", "A clear blue sky above you, visible through the branches",
    "path", "A path overgrown with weeds",
    "branches", "Dark tree branches arching above you",
    "trees", "The trees here stand tall and straight",
    "weeds", "These weeds cover the path you stand on",
  });
  replace_program("/room/room");
}
