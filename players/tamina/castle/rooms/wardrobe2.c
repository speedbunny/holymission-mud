/*  This is the Wardrobe Passage  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "A passage inside a Wardrobe";
	long_desc = 
"The stairs continue downwards, into a deeper gloom it would seem.\n"+
"It feels like this stairway is leading into the very depths of the\n"+ 
"earth itself...\n";

	dest_dir = ({
          CROOMS + "wardrobe","up",
	  CROOMS + "wardrobe3","down",
     });

	items = ({
  "stairs",
"Small, stone stairs curving up and down",
     });

	smell = "You can still smell the oaky wood of the wardrobe above you";

    ::reset (arg);

    RPR("room/room");
}
