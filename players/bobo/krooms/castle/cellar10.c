#include "std.h"
#include "../../../../obj/door.h"

object obj_1, obj_2;	/* Used by the MAKE_DOORS macro */

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
  if(!arg) {
  /* First reset */
    if(!present("north door")) { 

	MAKE_DOORS("players/bobo/krooms/castle/cellar10","north","players/bobo/krooms/castle/cellar11","south","iron","dungeiondoor","This is a solid-looking metal door.\n",1,1,1)
      return;
    }
  }

  obj_1->set_closed(1);
  obj_1->set_locked(1);
  obj_1->set_both_status();
} /* extra_reset */

ONE_EXIT(
	"players/bobo/krooms/castle/dungeon1","down",
	  "In the cellar",
	  "You are in the cellar of the castle.\nStairs lead down into a dungeon.\n", 1)
