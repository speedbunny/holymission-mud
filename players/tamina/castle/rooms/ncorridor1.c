/*  This is the North Corridor  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "North Corridor";
	long_desc = 
"You go west along the darkened corridor.  Here, the dusty floor,\n"+
"and empty torch-holders remind you of the earlier parts of Camelot.\n"+
"Ahead, you can almost see the end of this corridor.\n";

	dest_dir = ({
          CROOMS + "n_junction","east",
          CROOMS + "crypt","west",
        });

	items = ({
  "floor",
"This is covered in swirling clouds of dust as you walk across it",
  "torch-holder",
"And empty brace where wooden torches were held",
     });

    ::reset (arg);

    RPR("room/room");
}

