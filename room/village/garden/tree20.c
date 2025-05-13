inherit "/room/room";

#include <room_defs.h>
#include "tree.h"

void reset(int arg) {
  clone_list = ({
    1, 1, "squirrel", "obj/monster", ({
      "set_name", "squirrel",
      "set_short", "A squirrel", 
      "set_long", "A squirrel looking around for some food.\n",
      "set_race", "squirrel",
      "set_level", 5,
      "set_gender", 1 + random(2),
      "set_whimpy", 20,
    }),
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = 
    "You are about 25 feet off the ground at the trunk of an apple "+
    "tree.  Branches that even remotely have a chance of bearing your weight "+
    "stretch out to the north, east, west, and southwest. "+
    "Be careful not to jump off a branch or you may hurt yourself.\n";

  items = ({
    "trunk", "It is the base of the tree",
    "apples", "You may be able to reach them from the branches, but not "+
      "from here",
    "branch", "A long brown branch",
    "branches", "Long brown branches",
    "ground", "It is far below you",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "tree22", "north",
    VILLAGE_GARDEN + "tree23", "east",
    VILLAGE_GARDEN + "tree21", "west",
    VILLAGE_GARDEN + "tree25", "southwest",
    VILLAGE_GARDEN + "tree30", "up",
    VILLAGE_GARDEN + "tree05", "down",
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

