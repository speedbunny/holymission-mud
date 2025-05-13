inherit "/room/room";

#include <room_defs.h>
#include "tree.h"

status move(string str) {
  if(!str)
    str = query_verb();

  if(str=="southeast" && TP->query_size()>2 && !TP->IMM) {
    writelw("You are too big to go further out on the branch.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  mixed *tmp;

  tmp = random_bird();
  clone_list = ({
    1, tmp[0], "bird", "obj/monster", tmp[1],
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = 
    "You are about 25 feet off the ground. This branch is quite "+
    "sturdy and can support much weight. " +
    "Be careful not to jump off a branch or you may hurt yourself.\n";

  items = ({
    "branch", "A long brown branch",
    "branches", "Long brown branches",
    "ground", "It is below you",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "tree20", "northeast",
    VILLAGE_GARDEN + "tree26", "southeast",
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
}

