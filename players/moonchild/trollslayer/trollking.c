#include "room.h"

object troll;

#undef EXTRA_RESET
#define EXTRA_RESET\
  if(!present("troll")) {\
    move_object(troll=clone_object("players/moonchild/trollslayer/king"),this_object());\
  }

ONE_EXIT("players/moonchild/trollslayer/troll3", "north",
	"Troll king's hut",
	"This is the Troll King's Hut. The decor is gruesome in the extreme, skulls\n"
	+ "litter the floor, and everything is incredibly grubby. And it stinks too.\n", 1)

id(str) { return str=="skull" || str=="skulls"; }

long(str) {
  if(id(str)) {
    write("There are lots of skulls, mainly human, lying everywhere.\n");
    return 1;
  }
  ::long();
}
