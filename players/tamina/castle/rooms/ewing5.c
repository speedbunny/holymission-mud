/*  This is the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "East Wing";
	long_desc = 
"The small corridor leads north into the the shafts of light piercing \n"+
"the gloom that surrounds you.  Here you see that the light is coming\n"+
"from an open bed-chamber to the east.  The stone walls also continue\n"+
"the passage to the west, heading back into the castle itself.\n";

	dest_dir = ({
          CROOMS + "ewing4","south",
          CROOMS + "ebed2","east",
          CROOMS + "ewing6","west",
         });

    ::reset (arg);

    RPR("room/room");
}
