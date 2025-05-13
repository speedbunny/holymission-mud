/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";
object agravain;

reset(arg) {

  if (!agravain)
    MO (agravain = CLO (CMONS + "agravain"), TO);

  if (arg) return ;

      	set_light(0);
	short_desc = "West Wing";
	long_desc = 
"The passage at this point in the West Wing turns to head into the \n"+ 
"quadrant at the rear of Camelot.  You can sense air-movement ahead \n"+ 
"of you in the small corridor.\n";

	dest_dir = ({
          CROOMS + "wwing7","south",
          CROOMS + "wwing9","east",
        });

	smell = "You can smell fresh, clean air pushing through the dust "+
                "in the corridor.\n";

}

