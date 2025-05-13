/*  This is the West Corridor  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(0);
	short_desc = "West Corridor";
	long_desc = 
"You continue along the straight, dim corridor, leading to what seems\n"+
"to be a source of light ahead of you, emitting from the arched entrance \n"+
"you can see at the end of this corridor.  You can also smell that\n"+ 
"strange aroma that you encountered earlier.  It is definitely getting\n"+
"stronger as you get closer towards the arched portal ahead of you.\n";
 
	dest_dir = ({
          CROOMS + "nw_tower","north",
          CROOMS + "wcorridor1","south",
       });

	smell = "It smells like the burning of some sort of meat.\n";

	items = ({
  "arch",
"It looks like the entrance to the Tower is this corner of the castle, "+
"Camelot.  It would also seem that the source of the light and smell "+
"will be found behind the arch..",
  "entrance",
"It looks like the entrance to the Tower is this corner of the castle, "+
"Camelot.  It would also seem that the source of the light and smell "+
"will be found behind the arch..",
     });

    ::reset(arg);

    RPR("room/room");
}

