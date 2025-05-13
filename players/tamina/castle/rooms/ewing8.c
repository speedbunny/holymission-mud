/*  This is the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "East Wing";
	long_desc = 
"As you near the end of this straight corridor, you can feel cold \n"+ 
"draughts caress across your face.  Ahead of you, you can see a bend\n"+
"in the passage, leading to the west, to a larger chamber of some sort.\n";

	dest_dir = ({
          CROOMS + "ewing7","south",
          CROOMS + "ewing9","west",
       });

    ::reset (arg);

    RPR("room/room");
}
