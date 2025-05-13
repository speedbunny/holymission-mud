/*  This isthe Crypt  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "A Crypt under Camelot";
	long_desc = 
"This seems to be a central room in the Crypt of the castle, with \n"+
"three passages leading off from this chamber.  There is a high\n"+ 
"ceiling in this particular caved part, which would explain for the \n"+
"lighter aspect of the atmosphere.  However, you can still see very \n"+
"little of the rooms to which the passages lead.\n";

	dest_dir = ({
          CROOMS + "crypt4","south",
          CROOMS + "crypt7","east",
          CROOMS + "crypt5","west",
        });

	items = ({
  "passages",
"Very dark, and foreboding corridors, leading to who-knows where?",
  "passageways",
"Very dark, and foreboding corridors, leading to who-knows where?",
  "ceiling",
"It is a bit too high for you to get a good look at..",
     });

    ::reset (arg);

    RPR("room/room");
}
