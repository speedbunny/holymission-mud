inherit "room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "In the Deep forest, next to a small path";

  long_desc =
    "You are standing in the deep forest. Dark trees surround "+
    "you and you get the bad feeling that they are watching you. "+
    "But to the south the forest opens into a small, thin path "+
    "leading to a big, picturesque 'castle' on the top of a hill.\n";

  items = ({
    "forest","The dark forest surrounds you. It would be safer if "+
      "you took the path to the south",
    "trees","You get the strange feeling that they are watching you",
    "path","A small, thin path leading out of the dark forest",
    "castle","A big, picturesque castle, with strong stone walls "+
      "and two watchtowers",    
    "hill","You see a big grassy hill. The path is winding itself "+
      "in circles up the hill to a big castle",
    "walls","They look very sturdy",
    "watchtowers","There appears to be two that you can see",
  }); 

  smell = "You smell the fresh air of the forest.";

  dest_dir = ({
    FOREST + "forest04", "west",
    "/players/padrone/outside/path1", "south",
  });

  ::reset(arg);
  replace_program("room/room");
}
