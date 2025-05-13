/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "West wing ";
	long_desc = 
"The passage here twists to your right.\n"+
"Some way ahead, you can see a faint glimmer of light filtering into the\n"+
"darkened corridor.  It seems to be emitting from a chamber of some\n"+
"sorts.\n";

	smell = "You can only smell the old, dusty odour of the corridor.\n";

	dest_dir = ({
          CROOMS + "wwing2","south",
          CROOMS + "wwing4","west",
         });

    ::reset (arg);

    RPR("room/room");
}

