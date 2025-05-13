inherit "/room/room";

#include "/room/room_defs.h"

int move(string str) {
  if(!str)
    str=query_verb();
  if(str=="east") {
    write("A guard opens the gate to let you in.\n");
  }
  return ::move(str);
}

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "Right outside the western village gate";
  long_desc =
    "You stand just outside the western gate into the village. The "+
    "gate is closed to keep any dangers out of the village, but a "+
    "guard stands ready to let you in. A road leads west into the "+
    "wilderness.\n";

  dest_dir = ({
    HM_VILLAGE + "street11", "east",
    FOREST + "hump", "west",
  });

  items = ({
    "gate","A strong wooden gate in the stockade that surrounds the "+
      "village",
    "stockade","A defense wall made of sharply pointed poles",
    "village","A simple woodsmen's village lies east of here",
    "guard","You can't see him because he stands inside the gate",
    "road","Just another dusty dirt road, like you've seen many before",
  });
}

