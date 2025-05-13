/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "West wing (n,w)";
	long_desc = 
"You come down the passage into the weak shafts of light that play\n"+
"across the floor of the stone-work.  To your west, you can see\n"+
"the source of the light - windows in open rooms.\n";

	dest_dir = ({
          CROOMS + "wwing7","north",
          CROOMS + "wwing5","west",
         });

    ::reset (arg);

    RPR("room/room");
}

