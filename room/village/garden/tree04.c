inherit "/room/room";

#include <room_defs.h>
#include "tree.h"


status move(string str) {
  if(!str)
    str = query_verb();

  if(str=="north" && TP->query_size()>3 && !TP->IMM) {
    writelw("You are too big to go further out on the branch.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  mixed *tmp;

  apple_count = 4;
  tmp = random_insect();
  clone_list = ({
    1, tmp[0], "insect", "obj/monster", tmp[1],
  });

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
    VILLAGE_GARDEN + "tree03", "north",
    VILLAGE_GARDEN + "tree05", "south",
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
  add_action("_pick", "pick");
}

