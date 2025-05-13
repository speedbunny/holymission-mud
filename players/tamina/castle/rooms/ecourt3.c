/*  This is the East side of the Courtyard */

#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) 
{
  if (arg) return 0;

      	set_light(1);
	short_desc = "Courtyard ";
	long_desc = 
"You are at the North-East corner of the courtyard, sheltered completely\n"+ 
"from the strong wind.  The light is not as strong here, as it is in\n"+
"the centre of the courtyard.  There is very little you can see here in\n"+
"corner...\n";

	dest_dir = ({
          CROOMS + "ecourt2","south",
          CROOMS + "court3","west",         
        });

    ::reset (arg);

    RPR("room/room");

}
