inherit "/room/room";

#include <room_defs.h>
#include "tree.h"

status move(string str) {
  if(!str)
    str = query_verb();

  if(str=="up" && TP->query_size()>3 && !TP->IMM) {
    writelw("You are too big to climb further up the tree.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  mixed *tmp;

  tmp = random_insect();
  clone_list = ({
    1, tmp[0], "insect", "obj/monster", tmp[1],
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = 
    "You are about 15 feet off the ground at the trunk of an apple "+
    "tree.  Branches that only remotely have a chance of bearing your weight "+
    "stretch out to the north, east, and southwest. You also see more "+
    "apples that you might be able to reach in any of those directions "+
    "too. Be careful not to jump off a branch or you may hurt yourself.\n";

  items = ({
    "trunk", "It is the base of the tree",
    "apples", "You may be able to reach them from the branches, but not "+
      "from here",
    "branch", "A long brown branch",
    "branches", "Long brown branches",
    "ground", "It is far below you",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "tree04", "north",
    VILLAGE_GARDEN + "tree06", "east",
    VILLAGE_GARDEN + "tree10", "southwest",
    VILLAGE_GARDEN + "tree20", "up",
    VILLAGE_GARDEN + "garden3", "down",
  });
}

void init() {
  if(!TP->IMM && TP->query_size()>4) {
    write("You are too big to hold on to the tree and slide off.\n");
    TP->MOVEP("to the ground#" + VILLAGE_GARDEN + "garden3");
    return;
  }
  ::init();
  add_action("_jump", "jump");
}

