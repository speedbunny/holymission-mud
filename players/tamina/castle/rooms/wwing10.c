/*  This is the West Wing exit to the Quadrangle  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "West Wing Exit (s,e)";
	long_desc = 
"Here, you are standing at an exit leading east, out into a brightly \n"+
"lit, open quadrangle.  Occasional gusts of wind blow into the corridor \n"+ 
"here browned leaves, mixing with the dust on the floor.  Outside, you \n"+
"can see the large expanse of green grass in the square design.\n";

	dest_dir = ({
          CROOMS + "wwing9","south",
          CROOMS + "sw_corner","east",
        });

	items = ({
  "quadrangle",
"This is a large square-shaped area of green grass, flanked on each side "+
"by a cloistered pathway.  You can see some sort of garden away in the "+
"eastern part",
     });

}
