/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "West Wing ";
	long_desc = 
"Again, the passage here twists to the north.  And as you turn, you can\n"+
"instantly feel a cold draught smack on your face, and see bright light\n"+
"stain the flag-stones of an exit leading out to the east.\n";

	dest_dir = ({
          CROOMS + "wwing8","west",
          CROOMS + "wwing10","north",
        });

    ::reset (arg);

    RPR("room/room");
}

