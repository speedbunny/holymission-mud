#include "room.h"

object troll;

#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  if(!troll) {
    troll=clone_object("obj/monster");
    troll->set_name("troll");
    troll->set_short("A troll");
    troll->set_long("A hungry-looking troll.\n");
    troll->set_level(9);
    troll->set_aggressive(1);
    troll->set_al(-125);
    troll->set_wc(18);
    move_object(troll, this_object());
  }
}

ONE_EXIT("players/moonchild/trollslayer/troll3", "west",
	"Troll hut",
	"This is a very bare hut in the troll village. There are bloodstains on the\n"
	+ "wall, and the rest of the decor is certainly not all that much better.\n", 1)
