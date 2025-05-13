/*  This is the Underground Passage [wardrobe]  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "Underground Passage ";
	long_desc = 
"You decide to boldly venture into the underground passage.\n"+
"Here, the earthen passage continues to your east, or you can return\n"+ 
"west.  Other than that, there is very little that can catch your\n"+
"attention, apart from the worm falling in your hair, or torch...\n";

	dest_dir = ({
          CROOMS + "wardrobe3","west",
	  UND + "rm1","east",
     });

	items = ({
  "walls",
"Made entirely of earth now, with the occasional worm wriggling "+
"out of the dirt",
     });

    ::reset (arg);

    RPR("room/room");
}

