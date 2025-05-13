inherit "/room/room";

#include "/room/room_defs.h"

status move(string str) {
  if(!str)
    str = query_verb();
  if(str == "west") {
    writelw("A guard opens the gate and lets you through. The "+
            "guard closes the gate behind you.\n");
  }
  ::move(str);
}

void reset(int arg) {
  set_light(1);
  short_desc = "Village entrance";

  long_desc =
    "You have arrived just outside the eastern gate of "+
    "a village. The village is surrounded by a high wooden "+
    "stockade to keep out the dangers of the world. To the "+
    "east lies more roads that may extend to the sea.\n";

  dest_dir = ({
    EAST + "road01", "east",
    HM_VILLAGE + "street02", "west",
  });

  smell = "You smell fresh sea air from the east.";

  items = ({
    "forest","A huge forest awaits you silently",
    "road","A well-maintained dirt road",
    "village","A woodsmen's village. It looks a bit like the central village",
    "stockade","A wall of pointed wooden poles",
    "dangers","You have to enter the forest to find them",
    "gate","A guarded gate in the stockade leads to the village proper",
  });

  ::reset(arg);
  replace_program("room/room");
}

