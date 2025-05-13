/*  This is the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "East Wing ";
	long_desc = 
"You continue on through the seemingly empty passages of the old castle,\n"+ 
"Camelot.  Here the dusty corridor twists to your left, leading further \n"+ 
"into the eastern wing of the castle.\n";

	dest_dir = ({
          CROOMS + "ewing2","south",
          CROOMS + "ewing4","east",
         });

    ::reset (arg);

    RPR("room/room");
}

