inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The eastern part of Main Street";

  long_desc =
    "You walk on the eastern part of Main Street, which is "+
    "the biggest road through the village. East lies the "+
    "gate to the outside world. West leads to the village "+
    "square. At the sides of the road lie small gardens.\n";

  dest_dir = ({
    HM_VILLAGE + "street02", "east",
    HM_VILLAGE + "street04", "west",
  });

  items = ({
    "part","Main Street continues further west",
    "road","A well maintained dirt road",
    "village","A pleasant woodsmen village",
    "gate","A gate in the stockade is the entrance to the village",
    "stockade","A wall of pointed wooden poles to protect the village",
    "wilderness","You cannot see it through the closed gate",
    "square","A cobblestone square, just north of the church, is "+
      "the center of the village",
    "gardens","Small kitchen-gardens supply vegetables for the locals",
  });

  ::reset(arg);
  replace_program("room/room");
}

