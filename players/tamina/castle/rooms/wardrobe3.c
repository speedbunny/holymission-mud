/*  This is the Wardrobe Passage  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-2);
	short_desc = "The bottom of the Wardrobe Passage ";
	long_desc = 
"Finally, you reach the bottom of the staircase, and realise that \n"+
"you must be underground at this point.  You can feel the cold dank\n"+
"air of the earthy walls cling to your skin.  The smell is defnintely\n"+
"changing now as well.\n";

	dest_dir = ({
          CROOMS + "wardrobe2","up",
   	  CROOMS + "wardrobe4","east",
     });

	items = ({
  "walls",
"They are now carved out of the earth itself",
     });

	smell = "The musty odour of the ancient earth fills your nostrils";

     ::reset (arg);

     RPR("room/room");
}

