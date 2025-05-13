#include "std.h"
#include "../../../../obj/door.h"

object key;	/* Used by the MAKE_KEY macro */
object mirror;  /* magic mirror */

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
    if(!arg) {
	/* First reset */

  MAKE_KEY(key,"iron","dungeondoor");
  move_object(key,this_object());

  mirror=clone_object("/players/padrone/maze/magic_mirror");
  mirror->setup("players/kelly/rooms/castle/tower21bureau","players/padrone/maze/maze11","north");

  }
} /* extra_reset */

ONE_EXIT("players/kelly/rooms/castle/tower21","west","In a bureau",
	  "You are in a bureau of the castle.\n", 1)
