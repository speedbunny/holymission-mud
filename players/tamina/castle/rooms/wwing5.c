/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "West wing";
	long_desc = 
"You continue along this part of the passage spanning between two open\n"+
"bed-chambers.  Here the corridor branches again, allowing you to enter\n"+
"another room, continue onwards, or return to the Castle.\n";

	dest_dir = ({
          CROOMS + "wwing4","south",
          CROOMS + "wwing6","east",
          CROOMS + "wbed2","west",
         });

    ::reset (arg);

    RPR("room/room");
}

