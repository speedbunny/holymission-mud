inherit "/room/room";

#include <room_defs.h>
#include "tree.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In an apple tree";
  long_desc = 
    "You are about 40 feet off the ground and the view is beautiful. "+
    "There is nothing of interest up here except some leaves and "+
    "small twigs.\n";

  items = ({
    "twigs", "Small twigs growing out from the tree",
    "leaves", "They are quite green",
    "view", "The view is breath-taking. You can see over the buildings "+
      "to the north to see the town wall on the north side. To the "+
      "northwest you can see the tower of the meeting hall, while to "+
      "the west and south, the trees of the forest shoot up into the "+
      "sky. To the east is the fields where people grow crops. Plus, "+
      "the breeze is nice and relaxing",
    "ground", "It is far below you",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "tree30", "down",
  });
}

void init() {
  if(!TP->IMM && TP->query_size()>2) {
    write("You are too big to hold on to the tree and slide off.\n");
    TP->MOVEP("to the ground#" + VILLAGE_GARDEN + "garden3");
    return;
  }
  ::init();
  add_action("_jump", "jump");
}

