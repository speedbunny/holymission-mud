/*  This is the first Bedchamber in the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "Bed Chamber";
	long_desc = 
"Light does manage to force its way into this very dusty chamber, \n"+
"despite the amount of dirt on the small windows.  Around you, you can\n"+ 
"see several pieces of furniture which are not in as bad state as some \n"+
"other parts of Camelot at the moment.  There is a large bed, a\n"+ 
"chest-of-drawers, a box, and an iron pot at the side of the bed.\n";

	dest_dir = ({
          CROOMS + "wwing4","east",
        });

	items = ({
  "bed",
"A grandiose, four-poster bed, which looks suitable for someone very "+
"important",
  "drawers",
"A small chest-of-drawers, which is closed at the moment",
  "pot",
"A rather smelly chamber pot, at the side of the bed",
  "box",
"This is a wooden box, at the foot of the bed",
  "windows",
"The dirt on the windows does not allow you to see very far out of them",
     });

    ::reset (arg);

    RPR("room/room");
}
