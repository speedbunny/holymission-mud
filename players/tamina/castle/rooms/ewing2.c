/*  This is the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "East Wing";
	long_desc = 
"On taking the east branch of the corridor, you are plunged into a deeper\n"+
"darkness which you can almost touch.  A cloud of dust swirls around your\n"+
"feet as you proceed further into the heart of the desolate Camelot.\n"+
"You can see empty iron braces hanging from the stone walls, with \n"+
"strands of thread fluttering in the little breeze that pushes sluggishly\n"+
"through the empty veins of the castle.\n";

	dest_dir = ({
          CROOMS + "ewing3","north",
          CROOMS + "ecorridor","west",
         });

	items = ({
  "braces",
"These are old torch-holders, which look as though they have not been "
"used in some time",
  "threads",
"It looks as though these pieces of thread would have been parts of "
"magnificent tapestries that would have hung on these walls",
  "walls",
"These are very dusty and you cannot see much on them apart from "+
"the braces and remnants of tapestries",
     });

    ::reset (arg);
  
    RPR("room/room");
}
