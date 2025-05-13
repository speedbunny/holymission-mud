/*  This is a Bathroom */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
   if (arg) return ;

      	set_light(0);
	short_desc = "Bathroom ";
	long_desc = 
"This is now an old, dirty bathroom, that was once used by the monarchs.\n"+
"The old, iron tub has become very rusty, and does not look inviting.\n"+
"A cracked mirror hangs askew on the far east wall.\n";

	dest_dir = ({
          CROOMS + "bedroom","west",
     });

	items = ({
  "tub",
"A large, iron bath, that still contains rusty-brown water.  It "+
"does not look very inviting..",
  "mirror",
"Cracked in several places, it is very difficult to look into "+
"the mirror without straining your eyes.  But, you do see a "+
"strange-looking face gazing back intently at you..",
     });

}
