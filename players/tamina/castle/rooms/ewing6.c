/*  This is the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "East Wing";
	long_desc = 
"Here the passage twists again, running far ahead to the north, showing\n"+ 
"long walls dotted with occasional vacant torch-holders lining the stone.\n"+
"To the east, light can be seen dancing across the floor.\n";

	dest_dir = ({
          CROOMS + "ewing7","north",
          CROOMS + "ewing5","east",
         });

	items = ({
  "torch-holders",
"They look like empty eyes gazing blindly onto the corridor",
  "walls",
"What do you think?  Walls?",
     });

    ::reset (arg);

    RPR("room/room");
}

