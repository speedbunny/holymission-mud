/*  This is the West side of the Courtyard */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "Courtyard of Camelot";
	long_desc = 
"You are at the West side of the courtyard, standing alongside the wall\n"+
"sheltering from the blustery wind.  The sun is shining full onto you here\n"+
"but there is very little warmth to be felt.\n";

	dest_dir = ({
          CROOMS + "wcourt2","north",
          CROOMS + "courtyard","east",
          CROOMS + "wwing1","west",
         
     });

	items = ({
  "wall",
"This is a stone wall, which you think is of the West Wing of Camelot",
     });

    ::reset (arg);

    RPR("room/room");
}

