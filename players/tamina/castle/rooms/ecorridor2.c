/*  This is the East corridor  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "East Corridor ";
	long_desc = 
"You continue along the corridor in the eastern quarter of Camelot.\n"+
"Here the darkness seems to lessen slightly, as you see a faint glimmer\n"+
"of light from up ahead.  In this yellow glow, you can see an arched\n"+ 
"doorway, silhouetting several steps leading upwards...\n";

	dest_dir = ({
          CROOMS + "ne_tower","north",
          CROOMS + "ecorridor1","south",
        });

	items = ({
  "steps",
"Large steps leading upwards",
  "arch",
"A stone arched entrance, leading presumably to the tower you noticed "+
"earlier",
  "glow",
"It looks like natural light",
     });

    ::reset (arg);

    RPR("room/room");
}

