/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "West Wing";
	long_desc = 
"The small corridor continues here northward, in a\n"+
"straighter part of the castle.  To the south, \n"+
"there is more light playing across the floor.\n";

	dest_dir = ({
          CROOMS + "wwing8","north",
          CROOMS + "wwing6a","south",
         });

    ::reset (arg);

    RPR("room/room");
}
