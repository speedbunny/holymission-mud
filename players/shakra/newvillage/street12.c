/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "Right outside the western village gate";
  long_desc = "You stand just outside the western gate into the village. The gate\n"
        + "is closed to keep any dangers out of the village, but a guard stands\n"
        + "ready to let you in. A road leads west into the widerness.\n";
  dest_dir = ({ PATH+"street11","east",
        PATH+"street13","west" });
  items = ({"gate","A strong wooden gate in the stockade that surrounds the village",
        "stockade","A defense wall made of sharply pointed poles",
        "village","A simple woodsmen's village lies east of here",
        "guard","You can't see him because he stands inside the gate",
        "road","Just another dusty dirt road, like you've seen many before",
        });
  }

void init() {
  ::init();
  add_action("east","east");
  add_action("west","west");
  }

east() {
  write("A guard opens the gate to let you in.\n");
  return 0;
  }

west() {
  write("The road is currently blocked by a huge tree that was struck by lightning.\n");
  return 1;
  }

