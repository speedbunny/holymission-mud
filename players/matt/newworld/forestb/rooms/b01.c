inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Forest Entrance";
  long_desc =
    "    Just inside the Eastern Forest, this area is bright and\n" +
    "green. Birds chirp merrily, flitting from tree to tree and\n" +
    "filling the air with song; plants of every type abound here,\n" +
    "flourishing and plentiful, giving the place an earthy scent.\n" +
    "    You can see the road to the west.\n";
  smell = "A pleasant earthy scent hangs in the air here.";

  dest_dir = ({
    NWFORESTB + "rooms/b02", "east",
    NWROAD + "rooms/road03", "west",
  });

  items = ({
    "forest", "A brightly lit forest, green and peaceful",
    "trees", "Tall leafy trees",
    "tree", "Each tree is very old, but still healthy",
    "birds", "Brightly-colored birds singing merrily",
    "road", "North Road lies to the west",
    "plants", "All types of green plants",
  });
  replace_program("/room/room");
}
