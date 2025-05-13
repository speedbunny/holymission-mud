#include "std.h"
#include "../../../../obj/door.h"

object obj_1, obj_2;	/* Used by the MAKE_DOORS macro */

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
    if(!arg) { /* First reset */
      if(!present("north door")) {
        MAKE_DOORS("players/kelly/rooms/castle/cellar1", "north", "players/kelly/rooms/castle/cellar10", "south", "iron", "dungeondoor", "This is a solid-looking metal door.\n", 1, 1, 1)
	return;
      }
    }

    obj_1->set_closed(1);
    obj_1->set_locked(1);
    obj_1->set_both_status();
} /* extra_reset */

ONE_EXIT("players/kelly/rooms/castle/cellar", "east",
	  "In the cellar",
	  "You are in the cellar of the castle.\n", 1)
