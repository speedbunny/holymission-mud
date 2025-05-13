/* 031393 Changed by Llort to "room/room" */

inherit "room/room";

#include "config.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="Very dense bushes";
        long_desc=
	 "You are among some particularly dense and troublesome bushes.\n" +
	 "A nasty smell is coming from the east.\n";
        dest_dir=({
            "players/padrone/outside/back_yard", "north",
	    "players/padrone/garbage_heap", "east",	/* Not "outside" */
                 });
    }
}
