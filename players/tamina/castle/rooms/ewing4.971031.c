/*  This is the East Wing  */

#include "/obj/door.h"
#include "/players/tamina/defs.h"

inherit "room/room";
object obj_1,obj_2;

reset(arg) {

    if(!present("door")) {
  MAKE_DOORS("/players/tamina/castle/rooms/ewing4", "east", "/players/tamina/castle/rooms/ebed1", "west", "ivory", "keym1", "This appears to be a well-used door, with a strong lock.\n", 1,1,1);
    }
  if (arg) return ;

      	set_light(0);
	short_desc = "East Wing ";
	long_desc = 
"Here the corridor turns to the north, but also ends in a door leading to \n"+
"the east.  Ahead of you, light spills onto the stone slabs.\n";

	dest_dir = ({
          CROOMS + "ewing5","north",
          CROOMS + "ewing3","west",
         });

	property = ({"no_knock"});
}
