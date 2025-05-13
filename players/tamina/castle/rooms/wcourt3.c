/*  This is the West side of the Courtyard */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "Courtyard ";
	long_desc = 
"You are at the North-West corner of the courtyard, standing alongside\n"+ 
"the wall sheltered from the blustery wind.  The ground is quite furrowed\n"+ 
"here, with not as many weeds as other areas of the courtyard.\n";

	dest_dir = ({
          CROOMS + "court3","east",
          CROOMS + "wcourt2","south",
     });

	items = ({
  "wall",
"This is the stone wall, presumably of the East Wing of Camelot",
  "ground",
"It looks as though many people have walked around over this particular "+ 
"part of the ground",
     });

    ::reset (arg);

    RPR("room/room");
}
