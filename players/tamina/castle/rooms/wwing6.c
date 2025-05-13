/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "West wing ";
	long_desc = 
"As you proceed along the passage away from the lighted rooms, you\n"+
"are again plunged into the deep, oppressive darkness that closes\n"+
"around you like a blanket.  In the gloom, you can however see that\n"+
"the passage turns north here, heading further into Camelot.\n";

	dest_dir = ({
          CROOMS + "wwing7","north",
          CROOMS + "wwing5","west",
         });

    ::reset (arg);

    RPR("room/room");
}

