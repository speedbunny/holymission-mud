/*  This is the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "East Wing";
	long_desc = 
"This is a long, stretching part of the East Wing corridor, very \n"+
"different from the previous twists and turns.  The darkness around\n"+
"you seems to thicken as you proceed along the cramped passage.\n";

	dest_dir = ({
          CROOMS + "ewing8","north",
          CROOMS + "ewing6","south",
         });

    ::reset (arg);

    RPR("room/room");
}
