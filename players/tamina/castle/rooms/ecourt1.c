/*  This is the South-East corner of the courtyard */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "Courtyard ";
	long_desc = 
"Against the castle wall here, the courtyard is sheltered from the biting\n"+ 
"wind that is chilling your skin, despite the sunlight.  From here, you \n"+
"can see the whole of the courtyard spread out before you.  The East Wing\n"+ 
"Corridor of the castle starts to your left.\n";

	dest_dir = ({
          CROOMS + "courtyard","west",
          CROOMS + "ewing1","east",
          CROOMS + "ecourt2","north",
         
     });

	items = ({
  "walls",
"The walls of Camelot are now worn, and riddled with sprouting weeds "+
"and moss.  They do not portray an accurate picture of the usual "+ 
"gleaming walls of the Royal Castle of the King of England",
  "courtyard",
"The courtyard of Camelot was once a wondrous sight.. But now, it is "+
"saddening waste-ground, full of weeds",
     });

    ::reset (arg);

    RPR("room/room");
}

