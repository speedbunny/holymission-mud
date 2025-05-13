inherit "/room/room";

#include <room_defs.h>
#include "tree.h"

void reset(int arg) {
  apple_count = 4;

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = 
    "You are about 15 feet off the ground. This branch is quite "+
    "sturdy and can support much weight. @@apple_look@@" +
    "Be careful not to jump off a branch or you may hurt yourself.\n";

  items = ({
    "branch", "A long brown branch",
    "branches", "Long brown branches",
    "ground", "It is below you",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "tree02", "northeast",
    VILLAGE_GARDEN + "tree01", "northwest",
    VILLAGE_GARDEN + "tree04", "south",
  });
}

void init() {
  if(!TP->IMM && TP->query_size()>3) {
    write("You are too big to hold on to the tree and slide off.\n");
    TP->MOVEP("to the ground#" + VILLAGE_GARDEN + "garden3");
    return;
  }
  ::init();
  add_action("_jump", "jump");
  add_action("_pick", "pick");
}

