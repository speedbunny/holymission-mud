inherit "/room/room";

#include <room_defs.h>
#include "tree.h"

status move(string str) {
  if(!str)
    str = query_verb();

  if(str=="up" && TP->query_size()>2 && !TP->IMM) {
    writelw("You are too big to climb further up the tree.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  clone_list = ({
    1, 1, "hawk", "obj/monster", ({
      "set_name", "hawk",
      "set_race", "bird",
      "set_size", 2,
      "set_level", 7,
      "set_short", "A hawk",
      "set_long", "A hawk carefully guarding its nest.\n",
      "set_gender", 2,
    }),
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = 
    "You are about 35 feet off the ground at the trunk of an apple "+
    "tree. There are no branches that can support your weight. There "+
    "is a bird's nest here, @@extra_look@@The very top of the "+
    "tree is just above you.\n";

  items = ({
    "top", "It is above you",
    "trunk", "It is the base of the tree",
    "branch", "A small brown branch",
    "branches", "Small brown branches",
    "ground", "It is far below you",
    "nest", "It is a bird's nest",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "tree35", "up",
    VILLAGE_GARDEN + "tree20", "down",
  });
}

string extra_look() {
  if(present("bird"))
    return "and its resident is watching you as you move about. ";
  return "but it appears to be empty. ";
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

